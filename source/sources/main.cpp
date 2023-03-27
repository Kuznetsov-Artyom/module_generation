#include <iostream>
#include "../headers/generationModule.hpp"



int main(int argc, char* argv[], char** env)
{
    genRandData::IntegerGenerator<unsigned int> genInt(100, 100);
    genRandData::DoubleGenerator<float> genDbl(0, 5.0f);

    size_t countNumbers = 50;

    std::cout << "INTEGER\n";

    for (size_t i = 0; i < countNumbers; ++i)
    {
        std::cout << genInt() << '\n';
    }

    for (size_t i = 0; i < countNumbers; ++i)
    {
        std::cout << genDbl() << '\n';
    }

	std::cout << "NEW INTEGER\n";

	genInt.setRange(0, 5);

    for (size_t i = 0; i < countNumbers; ++i)
    {
        std::cout << genInt() << '\n';
    }


    return 0;
}