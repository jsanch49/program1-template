#ifndef  STAR_H
#define  STAR_H
#include "Planet.h"
#include "Vector.h"
#include "List.h"

class Starvector{
	private:
        Vector * planets;
	int next_id;
	int findIndex(long);
	public:
        Starvector();
	~Starvector();
        long addPlanet();
	bool removePlanet(long);
	Planet* getPlanet(long);
        void orbit();
        void printStarInfo();
        unsigned int getCurrentNumPlanets();
        //you may add any additional methodas you may need.
};

class Starlist{
	private:
        List * planets;
	int next_id;
	int findIndex(long);
	public:
        Starlist();
	~Starlist();
        long addPlanet();
	bool removePlanet(long);
	Planet* getPlanet(long);
        void orbit();
        void printStarInfo();
        unsigned int getCurrentNumPlanets();
        //you may add any additional methodas you may need.
};

#endif
