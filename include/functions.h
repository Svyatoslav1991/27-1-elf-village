#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <limits>

#include "branch.h"



//variable value input function
template <typename T>
T myCin() noexcept
{
    bool good = true;

    T variable;

    do
    {
        std::cout << "Enter the value of the variable: ";
        std::cin >> variable;

        good = std::cin.good();

        if (!good)
        {
            std::cout << "You entered something wrong\n";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!good);

    return variable;
}

const int64_t N = 5;

//Populate the elves by branches
void populateElves(Branch* branch) noexcept;

//Find the branch on which our elf sits
Branch* findElf(Branch* branch, std::string name) noexcept;

//Calculate the number of elves on a branch
int64_t countElves(Branch* branch) noexcept;

//show the inhabitants of the tree on the screen
void printTree(const Branch* branch, int64_t indent = 0) noexcept;

#endif// FUNCTIONS_H