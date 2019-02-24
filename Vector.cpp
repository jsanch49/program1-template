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
	delete this->array;
}

void Vector::copy(int elements, Planet ** from, Planet ** to) {
	for (int i = 0; i < elements; i++) {
		to[i] = from[i];
	}
}

void Vector::insert(int index, Planet * p) {
	if (p == NULL) return;
	if (this->array == NULL) {
		this->array = new Planet*[index+1];
		this->array[index] = p;
		this->vsize = index+1;
		return;
	}
	if (index < 0) return;
	if (this->vsize <= index) {
		//resize array index + 1
		Planet** cp = new Planet*[index+1];
		copy(this->vsize, this->array, cp);
		cp[index] = p;
		this->vsize = index+1;
		delete[] this->array;
		this->array = cp;
		return;
	} else {
		//add into array resize ++
		Planet** cp = new Planet*[this->vsize + 1];
		copy(index, this->array, cp);
		for (int i = index; i < this->vsize; i++) {
			cp[i+1] = this->array[i];
		}
		cp[index] = p;
		this->vsize++;
		delete[] this->array;
		this->array = cp;
		return;
	}
}


Planet* Vector::read(int index) {
	if (index < 0 || index >= this->vsize) return NULL;
	return this->array[index];
}

bool Vector::remove(int index) {
	if (index < 0 || index >= this->vsize) return false;
	Planet** ret = new Planet*[this->vsize - 1];
	copy(index, this->array, ret);
	for (int i = index+1; i < this->vsize; i++) {
		ret[i-1] = this->array[i]; 
	}
	delete this->array[index];
	delete this->array;
	this->array = ret;
	this->vsize--;
	return true;
}

unsigned Vector::size() {
	if (this->array == NULL) return 0;
	std::cout << vsize << std::endl;
	return this->vsize;
}
