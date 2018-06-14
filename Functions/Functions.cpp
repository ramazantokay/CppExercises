// Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// Function passing parameters by pointers
void ReturnSum(int intValeuA, int intValueB, int* outValue)
{
	*outValue = intValeuA + intValueB;
}
// Defining Struct
struct SumParameters
{
	int ValueA;
	int ValueB;
	int result;
};
// Create a new function with struct parameters
void ReturnSumStruct(SumParameters& params)
{
	params.result = params.ValueA + params.ValueB;
	cout << params.result << endl;
}

int main()
{
	/*int sum = 0;
	ReturnSum(3, 6, &sum);
	cout << sum << endl;*/

	cout << "/********************************************/" << endl;

	SumParameters sum;
	sum.ValueA = 5;
	sum.ValueB = 10;
	sum.result = 0;
	ReturnSumStruct(sum);




	return 0;
}

