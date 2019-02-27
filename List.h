#ifndef LIST_H
#define LIST_H

#include "Planet.h"
#include <cstdio>

class Node{
	 public:
	    Planet* p;
	    Node* prev;
	    Node* next;
	    Node(Planet *);
	    ~Node();
};	    
class List{
	 public:
	 Node * tail, * head;
	 int lsize;
	 void insert(int, Planet *);
	 Planet* read(int);
	 bool remove(int);
	 unsigned int size();
	 List();
	 ~List();
	 
 };
 #endif
	 	   
