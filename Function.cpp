#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include "Functions.h"


void currentWeekPlan(const int weeksPlanned)
{
    std::ofstream file("plannedWeek.txt");

    std::vector<std::string> userInputPlan;
    std::string strInput;


    for(int i = 0; i < weeksPlanned; i++)
    {
        std::cout << "Week ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << i + 1 << ".\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));

        for(int j = 0; j < 7; )
        {
            switch(j)
            {
                case 0:
                    std::cout << "Sunday: ";
                    break;
                case 1:
                    std::cout << "Monday: ";
                    break;
                case 2:
                    std::cout << "Tuesday: ";
                    break;
                case 3:
                    std::cout << "Wednesday: ";
                    break;
                case 4:
                    std::cout << "Thursday: ";
                    break;
                case 5:
                    std::cout << "Friday: ";
                    break;
                case 6:
                    std::cout << "Saturday: ";
            }
            
            if(!(std::cin >> strInput) || strInput == "")
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Input invalid, please try again...\n";
                continue;
            }

            userInputPlan.push_back(strInput);
            j++;
        }

        file << "Week "
             << i + 1
             << ": plan\n"
             << "-------------------\n";

        for (int j = 0; j < 7; j++)
        {
            switch(j)
            {
                case 0:
                    file << "Sunday: ";
                    break;
                case 1:
                    file << "Monday: ";
                    break;
                case 2:
                    file << "Tuesday: ";
                    break;
                case 3:
                    file << "Wednesday: ";
                    break;
                case 4:
                    file << "Thursday: ";
                    break;
                case 5:
                    file << "Friday: ";
                    break;
                case 6:
                    file << "Saturday: ";
            }
            file << userInputPlan.at(j);
        }
        
    }
}
void introduction()
{
    std::cout << "Alright, let's plan out your week! First, let's start by verifying the plan you would like to make.\n";

    int userInput;

    std::cout << "[1] 1 week plan\n"
              << "[2] 2 week plan\n"
              << "[3] 3 week plan\n";

    while(!(std::cin >> userInput))
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        std::cout << "Please enter a valid number, shown in the square brackets.\n\n";
        std::cout << "[1] 1 week plan\n"
                  << "[2] 2 week plan\n"
                  << "[3] 3 week plan\n";
    }

    if(userInput == 1)
    {
        currentWeekPlan(userInput);
    }
    else if(userInput == 2)
    {
        currentWeekPlan(userInput);
    }
    else if(userInput == 3)
    {
        currentWeekPlan(userInput);
    }
    else
    {
        std::cout << "Invalid input, we will redirect you to the part where we ask whether you would like to plan your week's out again.\n";
    }
}
char confirmationToRedoPlan()
{
    char confirmation;
    std::cout << "Would you like to replan your current plan?[Y/N]";

    while(!(std::cin >> confirmation))
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Would you like to replan your current week? Be sure to type in Y or N. ";
    }

    if(confirmation != 'Y' && confirmation != 'y' && confirmation != 'N' && confirmation != 'n')
    {
        std::cout << "We seem to notice that you typed in an option that isn't available. We will auto correct it to assume that you meant to not replan your week.\n";
        confirmation = 'n';
    }

    return confirmation;
}