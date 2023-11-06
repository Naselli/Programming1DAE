// IterationsDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	const int START {2};
    const int END   {24};
    const int INCREMENT {2};


    for (int counterForLoop{ START }; counterForLoop <= END ; counterForLoop += INCREMENT)
        std::cout << counterForLoop << " ";
    

    std::cout << std::endl;

    int counterWhileLoop{ START };
    while (counterWhileLoop <= END)
        std::cout << counterWhileLoop << " ";
        counterWhileLoop += INCREMENT;

    std::cout << std::endl;

    int counterDoWhileLoop{ START };
    do
    {
	    std::cout << counterDoWhileLoop << " ";
        counterDoWhileLoop += INCREMENT;
    }
    while (counterDoWhileLoop <= INCREMENT);
}
