class tactical(object):
    previousPlanets = []
    planetsLost = []
    
    def checkPlanets(self, gameinfo):
        #check if we have regained any planets since the last turn
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
            
            def closestPlus(output):
                closestsrc = max(gameinfo.my_planets.values(), key=lambda p: p.num_ships)
                closest = min(gameinfo.not_my_planets.values(), key=lambda p: p.distance_to(closestsrc))
                
                for planet in gameinfo.my_planets.values():
                    skip = False
                    try:
                        planet_distance = planet.distance_to(min([p for p in gameinfo.not_my_planets.values() if p.num_ships < planet.num_ships], key=lambda p: p.distance_to(planet)))
                        #print("planet found! distance is " + str(planet_distance))
                    except:
                        #if there are no planets that have less ships
                        planet_distance = 0
                        skip = True
                        #print("no planets found weaker than source!")
                    try:
                        closestsrc_distance = closestsrc.distance_to(min([p for p in gameinfo.not_my_planets.values() if p.num_ships < closestsrc.num_ships], key=lambda p: p.distance_to(closestsrc)))
                    except:
                        closestsrc_distance = 0
                        skip = True
                    
                
                    if planet_distance < closestsrc_distance and skip != True:
                
                        closestsrc = planet
                    
                        closest = min([p for p in gameinfo.not_my_planets.values() if p.num_ships < closestsrc.num_ships], key=lambda p: p.distance_to(closestsrc))
                    if output == "source":
                        return closestsrc
                    else:
                        return closest
                        
                
            #our weakest planet
            
            wkst = min(gameinfo.my_planets.values(), key=lambda p: p.num_ships)
            
            if wkst == src:
                wkst = False
            
            # Find the weakest planet
            weakest = min(gameinfo.not_my_planets.values(), key=lambda p: p.num_ships)
            
            #closest neutral
            try:
                closest_neutral = min([p for p in gameinfo.neutral_planets.values() if p.num_ships < src.num_ships], key=lambda p: p.distance_to(src))
            except:
                try:
                    closest_neutral = min(gameinfo.neutral_planets.values(), key=lambda p: p.distance_to(src))
                except:
                    closest_neutral = False
            
            #find the strongest planet that we have just lost that is weaker than our strongest planet
            
            closest = min(gameinfo.not_my_planets.values(), key=lambda p: p.distance_to(src))
            
            def outnumber():
                return len(gameinfo.my_planets) > len(gameinfo.not_my_planets)
             
            try:
                #only run if our planets outnumber their planets
                maxLost = max([p for p in planetsLost if p.num_ships < src.num_ships], key=lambda p: p.num_ships)
            except:
                maxLost = False
            
            # Find the strongest planet that is stronger than our strongest planet
            try:
                strongest = max([p for p in gameinfo.not_my_planets.values() if p.num_ships > src.num_ships], key=lambda p: p.num_ships)
            except:
                strongest = False
            
            # Find the closest planet that is weaker than our strongest planet
            try:
                closest_weakest = min([p for p in gameinfo.not_my_planets.values() if p.num_ships < src.num_ships], key=lambda p: p.distance_to(src))
            except:
                closest_weakest = False
            
            
    
            
            target = maxLost if maxLost and outnumber() else closestPlus("dest") #
            
            if target == closestPlus("dest"):
                src = closestPlus("source")
            
            
            if src != None:
                gameinfo.planet_order(src, target, src.num_ships)
            
            
