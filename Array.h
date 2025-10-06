

#pragma once

#include <iostream>

using namespace std;

// Class to hold multiple integer values
class Array {
public:
	// Overloaded constructor
	Array(const int);

	// Copy constructor
	Array(const Array&);

	// Destructor
	~Array();

	// Returns the size of the array
	int getSize() const;

	// Index operator
	int operator[](const int) const; // For reading from the Array
	int& operator[](const int); // For writing to the Array

	// Assignment operator
	Array& operator=(const Array&);

	// ostream << operator, inserts each array element into
	// the ostream ended with a newline
	friend ostream& operator<<(ostream& out, const Array& rhs);

	// Equality operator, check if an Array contains
	// an in-order subset of another Array
	bool operator==(const Array& rhs) const;

	// Less than operator, compares array elements one by one
	bool operator<(const Array& rhs) const;

	// Not operator, shuffles array
	Array& operator!();

	// Indirection operator, returns the smallest element
	int& operator*() const;

	// Compound sum operator, concatenates two arrays
	Array& operator+=(Array& rhs);

	// Postfix ++ operator, increases every element in the array
	Array operator++(int);

	// Prefix -- operator, decreases every element in the array
	Array& operator--();

	// Static method to get the total number of elements
	static int getNumberOfElements();
private:
	int* internalArray;
	int size;
	static int totalElements;
	static bool srandRan;
};

////////////////////////////////////////////////////////////////////////////////