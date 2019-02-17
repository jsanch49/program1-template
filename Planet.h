#ifndef PLANET_H
#define PLANET_H



class Planet{
	private:
		int id;
		int pos;
		int distance;
		char type;
	public:
		Planet(){this->id=-1;};
		Planet(int,int);
        int orbit();
	int getID() {return this->id;}
        int getDistance() {return this->distance;}
        int getPos() {return this->pos;}
	char getType() {return this->type;}
		//you may add any additional methods you may need.
};

#endif
