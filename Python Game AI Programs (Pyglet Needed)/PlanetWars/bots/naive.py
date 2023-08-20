import random

class naive(object):
    def update(self, gameinfo):
        
        
        #only send one fleet at a time
        #if gameinfo.my_fleets:
            #return

        # check if we should attack
        if gameinfo.my_planets and gameinfo.not_my_planets:
            src = max(gameinfo.my_planets.values(), key=lambda p: p.num_ships)
            # Find a target planet with the minimum number of ships.
            Min = min(gameinfo.not_my_planets.values(), key=lambda p: p.num_ships)
            
            # Find a target planet with the minimum distance to self
            Closest = min(gameinfo.not_my_planets.values(), key=lambda p: p.distance_to(src))
            
            # OR, (alternatively), use an inverse proportional maximum search...
            Max = max(gameinfo.not_my_planets.values(), key=lambda p: 1.0 / (1 + p.num_ships))

            
            
            gameinfo.planet_order(src, Closest, int(src.num_ships))
