class MinMax(object):
    def update(self, gameinfo):
        # only send one fleet at a time
        if gameinfo.my_fleets:
            return
        if gameinfo.my_planets and gameinfo.not_my_planets:
        # find the planet with the most ships
            src = max(gameinfo.my_planets.values(), key=lambda p: p.num_ships)
        
        # find the planet with the least ships
            dest = min(gameinfo.not_my_planets.values(), key=lambda p: p.num_ships)
        
        # alternatively, find the planet with the most inverse proportional ships
        # dest = max(gameinfo.not_my_planets.values(), key=lambda p: 1.0 / (1 + p.num_ships))
        
        # launch new fleet if there's enough ships
            if src.num_ships > 10:
                gameinfo.planet_order(src, dest, int(src.num_ships * 0.75))
