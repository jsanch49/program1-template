#ifndef STARVECTOR_H
#define STARVECTOR_H
#include "Planet.h"

class Star{
	private:
        int current_planets;
        int next_id;
	public:
        Planet **  planets;
        Star();
	~Star();
        int addPlanet();
	bool removePlanet(int);
	Planet* getPlanet(int);
        Planet* getFurthest();
        void orbit();
        void printStarInfo();
        int getCurrentNumPlanets() {return current_planets;}
        //you may add any additional methodas you may need.
};

#endif
