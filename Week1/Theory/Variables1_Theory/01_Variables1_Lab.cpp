// 01_Variables1_Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{\
	int pairOfShoes{10};			//4 bytes
	float price{68.9f};				//4 bytes
	char letter{'C'};				//1 byte
	bool isGrounded{true};			//1 byte
	double sienceNumber{3.1415};	//8 bytes

	//color are 1 byte
	//so you need 3 bytes for the color of a pixel (RGB)
	//4 bytes if you want to add alpha (A) to the color

	//In 3D API like OpeneGL or DirectX each color is a float.
	//a float is 4 bytes -> So for an RGBA color you need 16 bytes.

	char nutriWhat; //here we only declare, we don't init --> AVOID.
	char nutriBlah{}; //initialized to the default value.
	char nutriScore{ 'c' }; //initialized to 'C'.
	int numberOfStudents{};

	nutriBlah = 67; //this is not initializing, t changes the value.
	nutriScore = 94; //this is not initializing, it changes the value.
	nutriWhat = 64; // this IS initializing.

	//BINARY operators -> one operand on each side of the operator

	/*
	int a{10}, b{20}, c{};
	c = a + b;
	//std::cout << c;
	c = a / b;
	//std::cout << c;
	a = b * c;
	//std::cout << a;
	*/

	/*
	int a{10}, b{4};
	a += 2; //same as a = a + 2;
	a -= b; //same as a = a - b;
	b *= 4; //same as b = b * 4;
	b /= a; //same as b = b / a;
	int percentOperators { b %= a};
	std::cout << "b:" << b << " a:" << a << " -----> b %= a: " << percentOperators; 
*	 */

	int a{10}, b{4};
	++a;
	--b;




	//std::cout << "nutriScore: " << nutriScore;
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
