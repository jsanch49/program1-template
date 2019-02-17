#ifndef LIST_H
#define LIST_H

class Node{
	 public:
	    Planet* p;
	    Node* prev;
	    Node* next;
};	    
class List{
	 public:
	 Node * tail, * head;
	 int size;
 };
 #endif
	 	   
