#include "List.h"
#include <cstdio>
#include <iostream>

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
	this->lsize = 0;
}

List::~List() {
	if (head == NULL) {
		return;
	}
	if (head->next == NULL) {
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
	if (this->head == NULL) {
		this->head = new Node(p);
		this->tail = this->head;
		return;
	}
	Node* itr = head;
	Node* toAdd = new Node(p);
	if (index < 0) return;
	if (index >= this->lsize) {
		Node* current = tail;
		tail = toAdd;
		current->next = tail;
		tail->next = NULL;
		tail->prev = current;
		this->lsize++;
		return;
	} else if (index == 0) {
		toAdd->next = head;
		head->prev = toAdd;
		this->lsize++;
		std::cout << lsize << std::endl;
		return;
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
		return;
	}
}

Planet * List::read(int index) {
	if (index > this->lsize - 1) return NULL;
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

bool List::remove(int index) {
	if (index < 0 || (unsigned int)index >= this->size()) return false;
	Node* itr = head;
	if (itr == NULL) return false;
	if (index == 0) {
		if (head->next == NULL) {
			head = NULL;
			tail = NULL;
			lsize--;
			return true;
		}
		//Node* toRemove = head;
		head = head->next;
		delete head->prev;
		head->prev = NULL;
		lsize--;
		return true;
	}
	if ((unsigned int)index == this->size() - 1) {
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
		lsize--;
		return true;
	}
	int count = 1;
	while (itr->next != NULL) {
		if (index == count) {
			Node* current = itr; //keep, discard current->next
			Node* toRemove = current->next;
			Node * rest = toRemove->next;
			current->next = rest;
			rest->prev = current;
			delete toRemove;
			lsize--;
			return true;
		}
		count++;
		itr = itr->next;
	}
	return false;
}

unsigned List::size() {
	int ret = 1;
	if (head == NULL) return 0;
	while (head->next != NULL) {
		head = head->next;
		ret++;
	}
	std::cout << ret << std::endl;
	return ret;
}


