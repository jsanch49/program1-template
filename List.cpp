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
	if (index < 0) return;
	Node* np = new Node(p);
	if (head == NULL) {
		np->next = NULL;
		np->prev = NULL;
		head = np;
		tail = np;
	} else { //List is not empty
		if(index == 0) {
			np->next = head;
			head->prev = np;
			np->prev = NULL;
			head = np;
		} else if (index >= lsize) {
			np->prev = tail;
			np->next = NULL;
			tail->next = np;
			tail = np;
		} else {
			Node* itr = head;
			int count = 0;
			while (count < index-1) {
				itr = itr->next;
				count++;
			}
			np->prev = itr;
			np->next = itr->next;
			itr->next->prev = np;
			itr->next = np;
		}
	}
	this->lsize++;
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
	Node* itr = head;
	while (itr->next != NULL) {
		itr = itr->next;
		ret++;
	}
	//std::cout << ret << std::endl;
	return ret;
}


