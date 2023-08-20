
import random

class revolver:
    planetsLost = []
    previousPlanets = []
    
    def checkPlanets(self, gameinfo):
        #check if we have regained any planets since the last turn - THIS IS A FORM OF EVENT DETECTION
        if planetsLost != 0:
            for planet in planetsLost:
                if planet in gameinfo.my_planets.values():
                    planetsLost.remove(planet)
                    
        #if previous planets isn't empty, check if we've lost any planets
        if previousPlanets.length() != 0:
            for planet in previousPlanets:
                if planet not in gameinfo.my_planets.values():
                    planetsLost.append(planet)
                    
        #reset previous planets with our current planets for the next turn
        previousPlanets = []
        for planet in gameinfo.my_planets.values():
            previousPlanets.append(planet)
            
        #return planets that we have lost
        return planetsLost
        
    def update(self, gameinfo):
    
        if gameinfo.my_planets and gameinfo.not_my_planets:
        
            src = max(gameinfo.my_planets.values(), key=lambda p: p.num_ships)
            
            for planet in gameinfo.my_planets.values():
            
            
                #average attacking move - attack the closest enemy/neutral
                try:
                    closest = min([p for p in gameinfo.not_my_planets.values() if p.distance_to(planet) > 0 and p.num_ships < planet.num_ships], key=lambda p: p.distance_to(planet))
                except:
                    closest = min([p for p in gameinfo.not_my_planets.values() if p.distance_to(planet) > 0], key=lambda p: p.distance_to(planet))
                
                #find the biggest planet we just lost to try and defend
                try:
                    maxLost = max([p for p in planetsLost if p.num_ships < src.num_ships], key=lambda p: p.num_ships)
                except:
                    maxLost = False
                
                #scout the map by finding the weakest planets the furthest away to reduce fog
                try:
                    scout = max([p for p in gameinfo.enemy_planets.values() if p.num_ships < planet.num_ships], key=lambda p: p.distance_to(planet))
                except:
                    scout = False
                    
                
                
                #each planet is randomly assigned to being an attacker, defender, or scout, unless there is less than 10 planets owned
                choices = [closest, maxLost, scout]
                
                if maxLost == False:
                    choices.remove(maxLost)
                if scout == False:
                    choices.remove(scout)
                    
                #first phase of our bot - expansion
                if len(gameinfo.my_planets) < 10:
                    choices = [closest]
    
                #for phase 2 - randomly choose role
                target = random.choice(choices)
                
                gameinfo.planet_order(planet, target, target.num_ships)
                
            
            


#plan


#make self.plan = []

#consider strategy eg. attack, defend
#we wont use planetslost for defending, just choosing the planets we already own for reinforcing

#  FOR EACH PLANET WE OWN + potential planets
#set source variable to current planet
#consider initial actions to take eg. closest
#add this order to an associative array(source, dest, num_fleets), then put inside another array/class object that reprisents the "action/s" for a single turn

#then append the action/s (will be multiple actions but will need to be grouped as one so it can be executed in one frame) to self.plan

#if our fleet could claim the planet
#set source to this next planet
#repeat loop

#NOTE, there is a problem here. this logic does not consider the time it takes for a fleet to arrive. I dont know the speed that they travel so I may need a way to delay the order and do another order in the mean time.

#iterate through self.plan and execute action (consisting of each order) each turn/update

