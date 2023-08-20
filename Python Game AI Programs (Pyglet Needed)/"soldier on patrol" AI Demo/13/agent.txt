'''An agent with Seek, Flee, Arrive, Pursuit behaviours

Created for COS30002 AI for Games by Clinton Woodward <cwoodward@swin.edu.au>

For class use only. Do not publically share or post this code without permission.

'''

from vector2d import Vector2D
from vector2d import Point2D
from graphics import egi, KEY
from math import sin, cos, radians
from random import random, randrange, uniform
from random import uniform
from path import Path
from world import Circle


AGENT_MODES = {
    KEY._1: 'rifle',
    KEY._2: 'rocket',
    KEY._3: 'handgun',
    KEY._4: 'grenade',
    KEY._5: 'target',
    KEY._6: 'dead',
    KEY._7: 'patrol',
    KEY._8: 'attack',
}

class Agent(object):

    # NOTE: Class Object (not *instance*) variables!
    DECELERATION_SPEEDS = {
        'slow': 0.5,
        'normal': 1.0,
        'fast' : 2.0
        ### ADD 'normal' and 'fast' speeds here
    }

    def __init__(self, world=None, mode='seek'):
        # keep a reference to the world object
        self.world = world
        self.mode = mode
        # where am i and where am i going? random start pos
        dir = radians(random()*360)
        self.pos = Vector2D(randrange(world.cx), randrange(world.cy))
        self.vel = Vector2D()
        self.heading = Vector2D(sin(dir), cos(dir))
        self.side = self.heading.perp()
        self.scale = Vector2D(10, 10)  # easy scaling of agent size
        self.force = Vector2D()  # current steering force
        self.accel = Vector2D() # current acceleration due to force
        self.mass = 1.0
        self.target = None
        self.health = 1000
        self.current_dest = Vector2D(650,350)
        
        #fsm variables
        self.timer = 60
        self.lookout_time = 0
        self.frustration = 0
        self.alertness = 0
        
        # data for drawing this agent
        self.color = 'ORANGE'
        self.vehicle_shape = [
            Point2D(-1.0,  0.6),
            Point2D( 1.0,  0.0),
            Point2D(-1.0, -0.6)
        ]
        ### path to follow?
        self.path = Path()
        #set the path to a predetermined patrol route
        self.path.set_pts(
        [
            Vector2D(200, 700),
            Vector2D(700, 700),
            Vector2D(700, 200),
            Vector2D(200, 200),
            Vector2D(200, 700)
        ]
        
        )
        self.waypoint_threshold = 10.0

       
        # self.path = ??

        ### wander details
        # self.wander_?? ...
        # NEW WANDER INFO
        scale = 10
        self.wander_target = Vector2D(1, 0)
        self.wander_dist = 1.0 * scale
        self.wander_radius = 1.0 * scale
        self.wander_jitter = 10.0 * scale
        self.bRadius = scale
        # Force and speed limiting code
        self.max_speed = 20.0 * scale
        self.max_force = 500.0

        # limits?
        self.max_speed = 20.0 * scale
        ## max_force ??

        # debug draw info?
        self.show_info = True
        

    def calculate(self, delta):
        # calculate the current steering force
        mode = self.mode
        if self.health <= 0 or mode == 'dead':
            self.force = self.dead()
            return self.force
        #creating a timer so projectiles only shoot every 60 frames
        elif self.timer == 0:
            if mode == 'rifle':
                force = self.shoot('rifle', self.target)
                self.timer = 60
            elif mode == 'rocket':
                force = self.shoot('rocket', self.target)
                self.timer = 60
            elif mode == 'handgun':
                force = self.shoot('handgun', self.target)
                self.timer = 60
            elif mode == 'grenade':
                force = self.shoot('grenade', self.target)
                self.timer = 60
        else:
            force = Vector2D()
            self.timer -= 1
        if mode == 'target':
            self.color = 'RED'
            force = self.target_move()
        elif mode == 'seek':
            force = self.seek(self.world.target)
        elif mode == 'patrol':
            force = self.patrol()
        elif mode == 'wander':
            force = self.wander(delta)
        elif mode == 'attack':
            force = self.attack(self.target)
        else:
            force = Vector2D()
        self.force = force
        return force

    def update(self, delta):
        ''' update vehicle position and orientation '''
        # calculate and set self.force to be applied
        ## force = self.calculate()
        #force = self.calculate()  # <-- delta needed for wander
        ## limit force? <-- for wander
        force = self.calculate(delta)
        try:
            force.truncate(self.max_force)
        except:
            self.force = self.patrol()
            force = self.patrol()
            force.truncate(self.max_force)
            # <-- new force limiting code
        # Check for collisions with circles
        for circle in self.world.circles:
            circle.update()
            if self.is_colliding_with_circle(circle):
                
                self.health -= circle.damage
                print(self.health)
                
            
        # determine the new accelteration
        self.accel = force / self.mass  # not needed if mass = 1.0
        # new velocity
        self.vel += self.accel * delta
        # check for limits of new velocity
        self.vel.truncate(self.max_speed)
        # update position
        self.pos += self.vel * delta
        # update heading is non-zero velocity (moving)
        if self.vel.lengthSq() > 0.00000001:
            self.heading = self.vel.get_normalised()
            self.side = self.heading.perp()
        # treat world as continuous space - wrap new position if needed
        self.world.wrap_around(self.pos)

    def render(self, color=None):
        ''' Draw the triangle agent with color'''
        # draw the path if it exists and the mode is follow
        if self.mode == 'follow_path':
            ## ...
            pass

        # draw the ship
        egi.set_pen_color(name=self.color)
        pts = self.world.transform_points(self.vehicle_shape, self.pos,
                                          self.heading, self.side, self.scale)
        # draw it!
        egi.closed_shape(pts)
    
        # draw wander info?
        if self.mode == 'wander':
            # calculate the center of the wander circle in front of the agent
            wnd_pos = Vector2D(self.wander_dist, 0)
            wld_pos = self.world.transform_point(wnd_pos, self.pos, self.heading, self.side) # draw the wander circle
            egi.green_pen()
            egi.circle(wld_pos, self.wander_radius)
            # draw the wander target (little circle on the big circle)
            egi.red_pen()
            wnd_pos = (self.wander_target + Vector2D(self.wander_dist, 0))
            wld_pos = self.world.transform_point(wnd_pos, self.pos, self.heading, self.side)
            egi.circle(wld_pos, 3)

        # add some handy debug drawing info lines - force and velocity
        if self.show_info:
            s = 0.5 # <-- scaling factor
            # force
            egi.red_pen()
            egi.line_with_arrow(self.pos, self.pos + self.force * s, 5)
            # velocity
            egi.grey_pen()
            egi.line_with_arrow(self.pos, self.pos + self.vel * s, 5)
            # net (desired) change
            egi.white_pen()
            egi.line_with_arrow(self.pos+self.vel * s, self.pos+ (self.force+self.vel) * s, 5)
            egi.line_with_arrow(self.pos, self.pos+ (self.force+self.vel) * s, 5)

    def speed(self):
        return self.vel.length()
    
    def is_colliding_with_circle(self, circle):
        if self.mode == 'patrol' or self.mode == 'attack':
            return False
        return circle.isColliding(self.pos.x, self.pos.y)
        

    #--------------------------------------------------------------------------

    def seek(self, target_pos):
        ''' move towards target position '''
        desired_vel = (target_pos - self.pos).normalise() * self.max_speed
        return (desired_vel - self.vel)

   
    def flee(self, hunter_pos, delta):
        ''' move away from hunter position '''
        panic_distance = 100.0
        hide_distance = 1000.0

        if (self.pos - hunter_pos).length() < panic_distance:
            # Flee normally if hunter is within panic distance
            desired_vel = (self.pos - hunter_pos).normalise() * self.max_speed
            return (desired_vel - self.vel)
        else:
            # Find the closest circle to hide behind
            closest_circle = None
            min_distance = float('inf')
            for circle in self.world.circles:
                distance = (circle.position - self.pos).length()
                if distance < min_distance:
                    min_distance = distance
                    closest_circle = circle
                    
            egi.red_pen()
            egi.cross(closest_circle.position, 10.0)

            if closest_circle is not None and min_distance < hide_distance:
                # Hide behind the closest circle
                desired_vel = (closest_circle.position - self.pos).normalise() * self.max_speed
                return (desired_vel - self.vel)
            else:
                # No suitable circle to hide behind, flee normally
                return self.wander(delta)

    def arrive(self, target_pos, speed):
        ''' this behaviour is similar to seek() but it attempts to arrive at
            the target position with a zero velocity'''
        decel_rate = self.DECELERATION_SPEEDS[speed]
        to_target = target_pos - self.pos
        dist = to_target.length()
        if dist > 0:
            # calculate the speed required to reach the target given the
            # desired deceleration rate
            speed = dist / decel_rate
            # make sure the velocity does not exceed the max
            speed = min(speed, self.max_speed)
            # from here proceed just like Seek except we don't need to
            # normalize the to_target vector because we have already gone to the
            # trouble of calculating its length for dist.
            desired_vel = to_target * (speed / dist)
            return (desired_vel - self.vel)
        return Vector2D(0, 0)

    def pursuit(self, evader):
        '''This behavior predicts where an agent will be in time T and seeks
        towards that point to intercept it.'''
        # Calculate the distance to the evader
        to_evader = evader.pos - self.pos
        distance = to_evader.length()

        # Calculate the time it will take to reach the evader
        time = distance / self.max_speed
        
        #evader position
        evader_pos = evader.pos
        
        if distance < 100.0:
            # Predict the future position of the evader
            evader_pos = evader.pos + evader.vel * time

        # Seek towards the predicted position of the evader
        return self.seek(evader_pos)

    def wander(self, delta):
        ''' random wandering using a projected jitter circle '''
        wt = self.wander_target
        # this behaviour is dependent on the update rate, so this line must
        # be included when using time independent framerate.
        jitter_tts = self.wander_jitter * delta # this time slice
        # first, add a small random vector to the target's position
        wt += Vector2D(uniform(-1,1) * jitter_tts, uniform(-1,1) * jitter_tts)
        # re-project this new vector back on to a unit circle
        wt.normalise()
        # increase the length of the vector to the same as the radius
        # of the wander circle
        wt *= self.wander_radius
        # move the target into a position WanderDist in front of the agent
        target = wt + Vector2D(self.wander_dist, 0)
        # project the target into world space
        wld_target = self.world.transform_point(target, self.pos, self.heading, self.side) # and steer towards it
        return self.seek(wld_target)


    def randomise_path(self):
        cx = self.world.cx # width
        cy = self.world.cy # height
        margin = min(cx, cy) * (1/6) # use this for padding in the next line ...
        self.path.create_random_path(5, 0, 0, cx - margin, cy - margin) # you have to figure out the parameters
    
    # If heading to final point (is_finished?),
    def follow_path(self):
        if (self.path.is_finished()):
            # Return a slow down force vector (Arrive)
            return self.arrive(self.path.current_pt(), 'slow')
        else:
            # If within threshold distance of current way point, inc to next in path
            if (self.pos - self.path.current_pt()).length() < self.waypoint_threshold:
                #lookout time
                #self.path.inc_current_pt()
                self.lookout_time = 600
            egi.cross(self.path.current_pt(), 10)
            return self.seek(self.path.current_pt())
    # Else
    # If within threshold distance of current way point, inc to next in path
    # Return a force vector to head to current point at full speed (Seek)
    
    def dead(self):
        self.color = 'GREY'
        self.force = Vector2D()
        return self.pos
    
    def target_move(self):
    
        to_target = self.current_dest - self.pos
        distance = to_target.length()
        
        if self.current_dest == Vector2D(650, 350) and distance < 10:
            self.current_dest = Vector2D(310, 350)
        elif self.current_dest == Vector2D(310, 350) and distance < 10:
            self.current_dest = Vector2D(650, 350)
        return self.seek(self.current_dest)
    
    def shoot(self, mode, target):
        #def __init__(self, position, radius, damage, target, speed):
        
        if mode == 'rifle':
            radius = 4.0
            speed = 10.0
            accuracy = 30.0
        elif mode == 'rocket':
            radius = 10.0
            speed = 5.0
            accuracy = 30.0
        elif mode == 'handgun':
            radius = 4.0
            speed = 10.0
            accuracy = 75.0
        elif mode == 'grenade':
            radius = 30.0
            speed = 4.0
            accuracy = 75.0
           
        #a random
        #randrange(0 - accuracy,accuracy)
        offset = Vector2D(randrange(0 - accuracy,accuracy),0)
        
         # Calculate the direction to the target
        to_target = target.pos - self.pos
        distance = to_target.length()
        
        
        time = distance / speed
        
        # Predict the future position of the evader
        aim = offset + target.pos + (target.heading * time)#predicted position

        #instansiate circle with params
        self.world.circles.append(Circle(self.pos + Vector2D(0, radius), radius, 30.0, aim, speed))
        
        return self.force

    def patrol(self):
        #check if the patrolling agent can see an intruder within distance
        for agent in self.world.agents:
            if agent.mode != 'patrol' and agent.mode != 'attack' and agent.mode != 'dead':
                if (self.pos - agent.pos).length() < 200:
                    self.alertness += 600
                    self.target = agent
                    self.mode = 'attack'
        #if within distance to current point and lookout time has been allocated
        if self.lookout_time > 0:
            return self.lookout()
        else:
            #add modes for normal, alert, and high alert
            if self.alertness > 0:
                if self.alertness > 1000:
                    #HIGH ALERT
                    self.max_speed = 400
                    self.alertness -= 1
                else:
                    #ALERT
                    self.max_speed = 300
                    self.alertness -= 1
            else:
                self.max_speed = 200
            #follow the preexisting patrol pattern
            return self.follow_path()
            
    def attack(self, agent):
        #if target agent is not dead
        if agent.health > 0:
            #when gun timer (emulating fire rate) is done
            if self.timer == 0 :
                #gun mode determined by distance and time
                if (self.pos - agent.pos).length() < 100 and self.frustration < 300:
                    force = self.shoot('grenade', agent)
                elif (self.pos - agent.pos).length() < 100 and self.frustration >= 300:
                    force = self.shoot('handgun', agent)
                elif (self.pos - agent.pos).length() > 100 and self.frustration < 300:
                    force = self.shoot('rocket', agent)
                else:
                    force = self.shoot('rifle', agent)
                self.timer = 60
            else:
                self.timer -= 1
            #increment the attacking time (frustration)
            self.frustration += 1
            force = self.seek(agent.pos)
            
            return force
        else:
            self.frustration = 0
            self.mode = 'patrol'
            
        
    def lookout(self):
        difference = self.pos - self.path.current_pt()
        distance = difference.length()
        if self.speed() < 5 and distance < 5:
            self.lookout_time -= 1
            if self.lookout_time == 0:
                self.path.inc_current_pt()
           
            return Vector2D()
        else:
            return self.arrive(self.path.current_pt(), 'slow')
        
