#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include "Functions.h"

/*
    Challenge mode: The constraint for programming this program is listed below.

    1. This program must contain both an implementation file for functions used and a header file.

*/

int main()
{   
    char planAgain;
    do
    {
        introduction();
        planAgain = confirmationToRedoPlan();
    }
    while(planAgain != 'Y' && planAgain != 'y');

    std::cout << "Thank you for planning your day out strategically.\n"
              << "See you next time!" << std::endl;
    return 0;
}