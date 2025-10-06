

#include <iostream>
#include "Array.h"

int Array::totalElements = 0;
bool Array::srandRan = false;

// Helper function for the == operator
// Checks if a container Array contains a set Array in-order
bool hasSubset(const Array& container, const Array& set) {
	int matchedElements = 0;
	int needToMatch = set.getSize();

	for (int i = 0; i < container.getSize(); ++i) {
		// Match the set to the container
		if (set[matchedElements] == container[i]) {
			++matchedElements;
		}

		// Return true if the match was found
		if (matchedElements == needToMatch) {
			return true;
		}

		// Return false if it is impossible to match
		if (i + needToMatch - matchedElements >= container.getSize()) {
			return false;
		}
	}

	return false;
}

// Overloaded constructor
Array::Array(const int size) {
	this->size = size;
	this->internalArray = new int[size];

	totalElements += size;
}

// Copy constructor
Array::Array(const Array& copyFrom) {
	this->size = copyFrom.size;
	this->internalArray = new int[size];

	totalElements += size;

	for (int i = 0; i < this->size; ++i) {
		this->internalArray[i] = copyFrom.internalArray[i];
	}
}

// Destructor
Array::~Array() {
	delete[] this->internalArray;

	totalElements -= size;
}

// Returns the size of the array
int Array::getSize() const {
	return size;
}

// Index operator
int& Array::operator[](const int index) { // For reading from the Array
	if (index >= size || index < 0) { // For writing to the Array
		cout << "Index out of range!\n";
	}
	return internalArray[index];
}

int Array::operator[](const int index) const {
	if (index >= size || index < 0) {
		cout << "Index out of range!\n";
	}
	return internalArray[index];
}

// Assignment operator
Array& Array::operator=(const Array& rhs) {
	totalElements -= size;
	totalElements += rhs.size;

	size = rhs.size;
	int* newInternalArray = new int[size];

	for (int i = 0; i < rhs.size; ++i) {
		newInternalArray[i] = rhs[i];
	}

	delete[] internalArray;
	internalArray = newInternalArray;

	return *this;
}

// ostream << operator, inserts each array element into
// the ostream ended with a newline
ostream& operator<<(ostream& out, const Array& rhs) {
	for (int i = 0; i < rhs.size - 1; ++i) {
		out << rhs[i] << " ";
	}

	out << rhs[rhs.size - 1] << endl;

	return out;
}

// Equality operator, check if an Array contains
// an in-order subset of another Array
bool Array::operator==(const Array& rhs) const {
	return hasSubset(*this, rhs) || hasSubset(rhs, *this);
}

// Less than operator, compares array elements one by one
bool Array::operator<(const Array& rhs) const {
	for (int i = 0; i < (size < rhs.size ? size : rhs.size); ++i) {
		if (internalArray[i] > rhs[i]) {
			return false;
		}
		else if (internalArray[i] < rhs[i]) {
			return true;
		}
	}

	// All the compared elements are the same
	return false;
}

// Not operator, shuffles array
Array& Array::operator!() {
	// Use a static variable to keep track of
	// if srand was run or not so we can run it
	// only once
	if (!srandRan) {
		srandRan = true;
		srand(time(0));
	}

	// Use the Fish-Yates Shuffle to shuffle the array
	for (int i = 0; i < size; ++i) {
		int swapPos = rand() % (size - i) + i;
		int temp = internalArray[i];
		internalArray[i] = internalArray[swapPos];
		internalArray[swapPos] = temp;
	}

	return *this;
}

// Indirection operator, returns the smallest element
int& Array::operator*() const {
	int smallElementPos = 0;
	int smallElementValue = internalArray[0];

	for (int i = 1; i < size; i++) {
		int current = internalArray[i];
		if (current < smallElementValue) {
			smallElementPos = i;
			smallElementValue = current;
		}
	}

	return internalArray[smallElementPos];
}

// Compound sum operator, concatenates two arrays
Array& Array::operator+=(Array& rhs) {
	totalElements += rhs.size;

	int newSize = size + rhs.size;
	int* newArray = new int[newSize];

	for (int i = 0; i < size; ++i) {
		newArray[i] = internalArray[i];
	}

	for (int i = 0; i < rhs.size; ++i) {
		newArray[i + size] = rhs[i];
	}

	delete[] internalArray;
	internalArray = newArray;
	size = newSize;

	return *this;
}
// Postfix ++ operator, increases every element in the array
Array Array::operator++(int) {
	Array returnArray = *this;

	for (int i = 0; i < size; i++) {
		++(*this)[i];
	}

	return returnArray;
}

// Prefix -- operator, decreases every element in the array
Array& Array::operator--() {
	for (int i = 0; i < size; i++) {
		--(*this)[i];
	}

	return (*this);
}

// Static method to get the total number of elements
int Array::getNumberOfElements() {
	return Array::totalElements;
}

////////////////////////////////////////////////////////////////////////////////