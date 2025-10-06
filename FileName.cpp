/*
Program utilizes an Array class with overloaded operators
<<, !, *, ==, =, +=, <, --, ++ to run code in main for
expected output, the array class is split into 2 files
*/

#include "Array.h"


int main() {
	Array arr1(5), arr2(10);
	for (int i = 0; i < arr1.getSize(); i++)
		arr1[i] = i;
	for (int i = 0; i < arr2.getSize(); i++)
		arr2[i] = i;
	cout << "arr1 contains: " << arr1;
	cout << "arr2 contains: " << arr2;
	Array arr3(arr1);
	cout << "arr3 contains: " << arr3 << endl;
	arr2 = arr2;
	cout << "arr2 contains: " << arr2;
	arr3 = arr2;
	cout << "arr3 contains: " << arr3 << endl;
	cout << boolalpha;
	cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
	cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
	cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;
	arr3[0] = 100;
	cout << "New arr3: " << arr3;
	cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
	cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
	cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;
	arr1 += arr2;
	cout << "arr1 += arr2: " << arr1 << endl;
	cout << "!arr1: " << !arr1;
	cout << "*arr1: " << *arr1 << endl << endl;
	cout << "arr1++: " << arr1++;
	cout << "arr1 is: " << arr1 << endl;
	cout << "--arr1: " << --arr1;
	cout << "arr1 is: " << arr1 << endl;
	cout << "Total number of elements in all arrays: " << Array::getNumberOfElements() << endl;
	return 0;
}

