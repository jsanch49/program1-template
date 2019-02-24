#ifndef VECTOR_H
#define VECTOR_H

#include "Planet.h"
#include <cstdio>

class Vector{
	private:
	   Planet** array;
	   int vsize;
	   void copy(int, Planet**,Planet**);
	public:
	    void insert(int,Planet*);
	    Vector();
	   ~Vector();
	    Planet* read(int);
	    bool remove(int);
	    unsigned size();
	    
};
#endif	    
		
