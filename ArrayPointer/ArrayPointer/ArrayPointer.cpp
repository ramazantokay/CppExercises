// ArrayPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	//Array Part
	int intArray[5] = { 1,2,3,4,5 }; // Creating new int array 
	cout << "Summation is : " << intArray[0] + intArray[4] << endl; // Sum 1. and 5. members and print out in the screen.

	int index = 0;
	while (index < 5)
	{
		cout << (index)+1 << "." << "member is :" << intArray[index] << endl;
		index++;
	}
	cout << "\n";
	cout << "/**********************************************/ \n" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << intArray[i] << endl;

	}

	//Pointer Part
	cout << "\n";
	cout << "/**********************************************/ \n" << endl;

	int variable = 5; //Declaring a variable
	int* variablePointer = &variable; // Declaring a pointer which stores the address of variable

	cout << "Value of variable: " << variable << endl;
	cout << "Address of variable: " << &variable << endl;
	cout << "Value of variablePointer: " << variablePointer << endl;
	cout << "Value of VariablePointer + 1 : " << variablePointer + 1 << endl;
	cout << "Value of memory at dereferenced variablePointer: " <<*variablePointer <<endl;
	cout << "Value of memory at dereferenced variablePointer + 1: " << *variablePointer + 1 <<"\n"<< endl;



	

}

