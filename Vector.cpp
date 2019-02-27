#include "Vector.h"
#include <iostream>

Vector::Vector() {
	this->array = NULL;
	this->vsize = 0;
}

Vector::~Vector() {
	for (int i = 0; i < this->vsize; i++) {
		delete this->array[i];
	}
	delete[] this->array;
}

void Vector::insert(int index, Planet * p) {
	if (p == NULL) return;
	if (index < 0) return;
	if (this->array == NULL) {
		this->array = new Planet*[index+1];
		this->array[index] = p;
		this->vsize = index+1;
		//intiliaze other indexes to NULL
		for(int i = 0; i < this->vsize; i++) {
			if (i == index) continue;
			this->array[i] = NULL;
		}
		return;
	}
	int resize = index + 1;
	if (index < this->vsize) resize = this->vsize+1;
	Planet** cp = new Planet*[resize];
	if (index > this->vsize) {
		for (int i = 0; i < this->vsize; i++) {
			cp[i] = this->array[i];
		}
		for (int i = this->vsize; i < resize; i++) {
			if (i == index) {
				cp[i] = p;
				continue;
			}
			cp[i] = NULL;
		}
	} else {
		for (int i = 0; i < index; i++) {
			cp[i] = this->array[i];
		}
		cp[index] = p;
		for (int i = index+1; i < resize; i++) {
			cp[i] = this->array[i-1];
		}
	}
	this->vsize = resize;
	delete[] this->array;
	this->array = cp;
}


Planet* Vector::read(int index) {
	if (index < 0 || index >= this->vsize) return NULL;
	return this->array[index];
}

bool Vector::remove(int index) {
	if (index < 0 || index >= this->vsize) return false;
	Planet** ret = new Planet*[this->vsize - 1];
	for (int i = 0; i < index; i++) {
		ret[i] = this->array[i];
	}
	for (int i = index+1; i < this->vsize; i++) {
		ret[i-1] = this->array[i]; 
	}
	delete this->array[index];
	delete[] this->array;
	this->array = ret;
	this->vsize--;
	return true;
}

unsigned Vector::size() {
	if (this->array == NULL) return 0;
	//std::cout << vsize << std::endl;
	return this->vsize;
}
