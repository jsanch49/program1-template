#include "List.h"

Node::Node(Planet * p) {
	this->p = p;
	this->next = NULL;
	this->prev = NULL;
}

Node::~Node() {
	delete this->p;
}

List::List() {
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

List::~List() {
	if (head == NULL) {
		return;
	}
	if (head->next == NULL {
		delete(head);
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		Node* toFree = temp;
		temp = temp->next;
		delete(toFree);
	}
	delete(temp);
}

void List::insert(int index, Planet * p) {
	Node* itr = head;
	Node* toAdd = new Node(p);
	if (index < 0) return;
	if (index >= this->size) {
		toAdd->prev = this->tail;
		this->tail->next = toAdd;
		this->size++;
	} else if (index == 0) {
		toAdd->next = head;
		head->prev = toAdd;
		this->size++;
	} else {
		int i = 0;
		while ( i < index-1) {
			i++;
			itr = itr->next;
		}
		//itr points to element before index
		Node* after = itr->next;
		itr->next = toAdd;
		toAdd->prev = itr;
		toAdd->next = after;
		after->prev = toAdd;
	}
}

Planet * List::read(int index) {
	if (index > this->size - 1) return NULL;
	if (index == 0) return head->p;
	Node* itr = head;
	int i = 0;
	while( itr != NULL) {
		if (i == index) {
			return itr->p;
		}
		itr = itr->next;
		i++;
	}
	return NULL;
}


