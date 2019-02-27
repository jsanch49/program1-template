#ifndef VECTOR_H
#define VECTOR_H

#include "Planet.h"
#include <cstdio>

class Vector{
	private:
	   Planet** array;
	   int vsize;
	public:
	    void insert(int,Planet*);
	    Vector();
	   ~Vector();
	    Planet* read(int);
	    bool remove(int);
	    unsigned size();
	    
};
#endif	    
		
