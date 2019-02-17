#ifndef VECTOR_H
#define VECTOR_H

class Vector{
	private:
	   Planet* array;
	   int size;
	   void copy(int, Planet*,Planet *);
	public:
	    void insert(int,Planet*);
	   ~Vector();
	    Planet* read(int);
	    bool remove(int);
	    unsigned size();
	    
};
#endif	    
		
