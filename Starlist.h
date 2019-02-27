#ifndef  STARLIST_H
#define  STARLIST_H
#include "Planet.h"
#include "Vector.h"

class Star{
	private:
        Vector * planets;
	public:
        Starlist();
	~Starlist();
        long addPlanet();
	bool removePlanet(int);
	Planet* getPlanet(int);
        void orbit();
        void printStarInfo();
        unsigned int getCurrentNumPlanets();
        //you may add any additional methodas you may need.
};

#endif
