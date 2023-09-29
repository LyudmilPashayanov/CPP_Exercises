// TemplatesExercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>
T Greater(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}


int main()
{
    std::cout << Greater("asdf", "bbb");
}