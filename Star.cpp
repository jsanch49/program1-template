#include "Star.h"
#include <iostream>
#include <cstdlib>
#include <time.h>


Star::Star() {
	this->planets = NULL;
	this->current_planets = 0;
	this->next_id = 1001;
}

Star::~Star() {
	for (int i=0;i < this->current_planets; i++) delete this->planets[i];
	delete[] this->planets;
}

int Star::addPlanet() {
	Planet ** newPlanets = new Planet*[++(this->current_planets)];//if planets=NULL should work
	Planet * planet = new Planet(rand(),this->next_id++);
	newPlanets[this->current_planets-1] = planet;
	if (this->planets == NULL) {
	       	this->planets = newPlanets;
		return planet->getID();
	}
	else {
		for (int i=0; i < this->current_planets-1; i++) newPlanets[i] = this->planets[i];
	}
	delete[] this->planets;
	this->planets = newPlanets;
	return planet->getID();
}

bool Star::removePlanet(int id) {
	int idxToRmv = -1;
	for (int i=0; i < this->current_planets; i++) if (this->planets[i]->getID()==id) {idxToRmv=i;break;};
	if (idxToRmv==-1) return false;//if idx not updated then Planet not in Star->planets
	Planet ** newPlanets = new Planet * [--this->current_planets];
	int current=0;
	for (int i=0; i < this->current_planets+1; i++) if (i!=idxToRmv) newPlanets[current++] = this->planets[i];;
	delete this->planets[idxToRmv];
	delete[] this->planets;
	this->planets = newPlanets;
	return true;
}

Planet* Star::getPlanet(int id) {
	for (int i=0; i < this->current_planets; i++) {
		if (this->planets[i]->getID() == id) {
			return this->planets[i];
		}
	}
	return NULL;
}

Planet* Star::getFurthest() {
	int max = 0;
	for (int i = 0; i < this->current_planets; i++) {
		max = (this->planets[i]->getDistance() > this->planets[max]->getDistance())? i: max;
	}
	return this->planets[max];
}

void Star::orbit() {
	if (this->current_planets == 0) return;
	for (int i = 0; i < this->current_planets; i++) {
		this->planets[i]->orbit();
	}
}

void Star::printStarInfo() {
	std::cout << "The star has " << this->current_planets << " planets." << std::endl;
	std::cout << "Planets:\n";
	for (int i = 0; i < this->current_planets; i++) {
		Planet* info = this->planets[i];
		std::cout << "Planet " << info->getType() << info->getID() << " is " << info->getDistance() << " miles away at position " << info->getPos() << " around the star." << std::endl;
	}
}

