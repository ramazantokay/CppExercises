// FlowControl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
enum class Colors
{
	Red,
	Green,
	Blue
};

int main()
{
	Colors color = Colors::Red;
	switch (color)
	{
	case Colors::Red:
		cout << "The color is Red" << endl;
		break;
	case Colors::Green:
		cout << "The color is Green" << endl;
		break;
	case Colors::Blue:
		cout << "The color is Blue" << endl;
		break;
	default:
		break;
	}
	int i = 1;

	while (i<6)
	{
		cout << "Hello" << i << endl;
		i++;
	}

	return 0;
}

