#include "Vector.h"

Vector::~Vector() {
	delete this->array;
}

void Vector::copy(int elements, Planet * from, Planet * to) {
	for (int i = 0; i < elements; i++) {
		to[i] = from[i];
	}
}

void Vector::insert(int index, Planet * p) {
	if (p == NULL) return;
	if (this->array == NULL) {
		this->array = new Planet*[index+1];
		this->array[index] = p;
		this->size = index+1;
	}
	if (index < 0) return;
	if (this->size <= index) {
		//resize array index + 1
		Vector* cp = new Planet*[index+1];
		copy(this->size, this->array, cp);
		cp[index] = p;
		this->size = index+1;
		delete this->array;
		this->array = cp;
	} else {
		//add into array resize ++
		Planet* cp = new Planet*[this->size+1];
		copy(index, this->array, cp);
		for (int i = index; i < this->size; i++) {
			cp[i+1] = this->array[i];
		}
		cp[index] = p;
		this->size++;
		delete this->array;
		this->array = cp;
	}
}


Planet* Vector::read(int index) {
	if (index < 0 || index >= this->size) return NULL;
	return this->array[index];
}

bool Vector::remove(int index) {
	if (index < 0 || index >= this->size) return false;
	Vector* ret = new Vector*[this->size - 1];
	copy(index, this->array, ret);
	for (int i = index+1; i < this->size; i++) {
		ret[i-1] = this->array[i]; 
	}
	delete this->array[index]
	delete this->array;
	this->array = ret;'
	this->size--;
	return true;
}

unsigned Vector::size() {
	return sizeof(this->array);
}
