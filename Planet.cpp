#include "Planet.h"
#include <cstdlib>
#include <time.h>

Planet::Planet(int distance){
	this->id = id;
	this->distance = distance;
        this->pos = rand()%360;
	switch (rand()%3) {
		case 0:
			this->type = 'h';
			break;
		case 1:
			this->type = 'r';
			break;
		case 2:
			this->type = 'g';
			break;
	}
}

int Planet::orbit() {
	this->pos++;
	this->pos = this->pos%360;
	return this->pos;
}


