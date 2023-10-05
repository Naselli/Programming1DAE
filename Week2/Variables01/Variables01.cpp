#include <iostream>

int main()
{
    //-------------------------------------------------------------------------
    
    int numberOne{}; 
    
    std::cout << "Give a number: ";
    
    std::cin >> numberOne;
    std::cout << "\n";
    std::cout << "The number is: " << numberOne << std::endl;
    
    //-------------------------------------------------------------------------
    
    int number1{}, number2{};
    
    std::cout << "Give two numbers.";
    std::cin >> number1 >> number2;
    
    std::cout << "The first number is: " << number1 << std::endl;
    std::cout << "The second number is: " << number2 << std::endl;
    
    //-------------------------------------------------------------------------
    
    int r{}, g{}, b{}, a{};

    std::cout << "RGBA in [0, 255]? -> ";
    std::cin >> r >> g >> b >> a;
    std::cout << "RGBA in [0.0f, 1.0f]" << std::endl;
    std::cout << r / 255.00 << std::endl;
    std::cout << g / 255.00 << std::endl;
    std::cout << b / 255.00 << std::endl;
    std::cout << a / 255.00 << std::endl;
    
    //-------------------------------------------------------------------------
    
    double distance{};
    std:: cout << "Distance in km? -> ";
    std:: cin >> distance;
    std:: cout << distance * 1000 << " meters. " << distance * 100000 <<  " cm";
    
    //-------------------------------------------------------------------------
    
    int angle{};
    const double pi{3.14159265358979323846};

    std::cout << "Angles in degrees? -> ";
    std::cin >> angle;
    std::cout << angle * pi / 180.00 << " radians.";
    
    //-------------------------------------------------------------------------
    
    int secondsOfOneRotation{};
    std::cout << "Seconds of one rotations? -> ";
    std::cin >> secondsOfOneRotation;
    std::cout << 360 / secondsOfOneRotation << " degrees/second";
    
    //-------------------------------------------------------------------------
    
    double speed;
    double elapsedTime;

    std::cout << "Speed (km/h)? -> ";
    std::cin >> speed;
    std::cout << "Elapsed time (minutes)? -> ";
    std::cin >> elapsedTime;
    std::cout << (speed / 60 * elapsedTime) * 1'000 << " meters";
    
    //-------------------------------------------------------------------------
    
    double seconds;
    const double gravity{9.81};
    
    std::cout << "Seconds? -> ";
    std::cin >> seconds;
    std::cout << "Velocity " << seconds * gravity << " m/sec.";
    
    //-------------------------------------------------------------------------
    
    int radius;

    std::cout << "Radius of circle? -> ";
    std::cin >> radius;
    std::cout << "Circumference: " << 2.00 * pi * radius << std::endl;
    std::cout << "Area: " << pi * radius * radius;
    
    //-------------------------------------------------------------------------
    int width{}, height{};
    
    std::cout << "Width and height? -> ";
    std::cin >> width >> height;
    //std::cout << "Circumference: " << ;
    //std::cout << "Area: " << ;


    //system("PAUSE");
}

