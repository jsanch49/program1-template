#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Star.h"

Starlist::Starlist() {
	this->planets = new List();
	this->next_id = 0;
}

Starlist::~Starlist() {
	delete this->planets;
}

int Starlist::findIndex(long addr) {
	for (unsigned int i = 0; i < this->planets->size(); i++) {
		Planet * p = this->planets->read(i);
		if (p == NULL) continue;
		if (p->getID() == addr) return i;
	}
	return -1;
}

int Starvector::findIndex(long addr) {
	for(unsigned int i = 0; i < this->planets->size(); i++) {
		Planet * p = this->planets->read(i);
		if (p == NULL) continue;
		if (p->getID() == addr) return i;
	}
	return -1;
}

long Starlist::addPlanet() {
	Planet * planet = new Planet(rand()%10000);
	this->planets->insert(this->next_id++, planet);
	return (long)planet;
}

bool Starlist::removePlanet(long id) {
	int idx = findIndex(id);
	if (idx==-1) return false;
	return this->planets->remove(idx);
}

Planet* Starlist::getPlanet(long id) {
	int idx = findIndex(id);
	if (idx == -1) return NULL;
	return this->planets->read(idx);
}

void Starlist::orbit() {
	if (this->planets->size() == 0) return;
	if (this->planets == NULL) return;
	Node* itr = this->planets->head;
	while(itr->next != NULL) {
		itr->p->orbit();
		itr = itr->next;
	}
	itr->p->orbit();
}

void Starlist::printStarInfo() {
	std::cout << "The starlist has " << getCurrentNumPlanets() << " planets." << std::endl;
	std::cout << "Planets:\n";
	for (unsigned int i = 0; i < this->planets->size(); i++) {
		Planet* info = this->planets->read(i);
		if (info == NULL) continue;
		std::cout << "Planet " << info->getType() << info->getID() << " is " << info->getDistance() << " miles away at position " << info->getPos() << " around the star." << std::endl;
	}
}

unsigned int Starlist::getCurrentNumPlanets() {
	return this->planets->size();
}

Starvector::Starvector() {
	this->planets = new Vector();
	this->next_id = 0;
}

Starvector::~Starvector() {
	delete this->planets;
}

long Starvector::addPlanet() {
	Planet * planet = new Planet(rand()%10000);
	this->planets->insert(this->next_id++, planet);
	return (long)planet;
}

bool Starvector::removePlanet(long id) {
	int idx = findIndex(id);
	if (idx == -1) return false;
	return this->planets->remove(idx);
}

Planet* Starvector::getPlanet(long id) {
	int idx = findIndex(id);
	if (idx == -1) return NULL;
	return this->planets->read(idx);
}

void Starvector::orbit() {
	if (this->planets->size() == 0) return;
	for (unsigned int i = 0; i < this->planets->size(); i++) {
		Planet * p = this->planets->read(i);
		if (p == NULL) continue;
		p->orbit();
	}
}

void Starvector::printStarInfo() {
	std::cout << "The starlist has " << getCurrentNumPlanets() << " planets." << std::endl;
	std::cout << "Planets:\n";
	for (unsigned int i = 0; i < this->planets->size(); i++) {
		Planet* info = this->planets->read(i);
		if (info == NULL) continue;
		std::cout << "Planet " << info->getType() << info->getID() << " is " << info->getDistance() << " miles away at position " << info->getPos() << " around the star." << std::endl;
	}
}

unsigned int Starvector::getCurrentNumPlanets() {
	int ret = 0;
	for (unsigned int i = 0; i < this->planets->size(); i++) {
		Planet * p = this->planets->read(i);
		if (p) ret++; //will not incremenet if p is null
	}
	return ret;
}




