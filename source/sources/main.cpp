#include <iostream>
#include "../headers/generationModule.hpp"



int main(int argc, char* argv[], char** env)
{
    genRandData::IntegerGenerator<unsigned int> genInt(0, UINT32_MAX);
    genRandData::DoubleGenerator<double> genDbl(__DBL_MIN__, __DBL_MAX__);
     genRandData::CharGenerator<int8_t> genChar(CHAR_MIN, CHAR_MAX);

    size_t countNumbers = 50;

    std::cout << "\nINTEGER\n";

    for (size_t i = 0; i < countNumbers; ++i)
    {
        std::cout << genInt() << '\n';
    }

    std::cout << "\nDOUBLE\n";

    for (size_t i = 0; i < countNumbers; ++i)
    {
        std::cout << genDbl() << '\n';
    }

	std::cout << "\nNEW INTEGER\n";

	genInt.setRange(0, 5);

    for (size_t i = 0; i < countNumbers; ++i)
    {
        std::cout << genInt() << '\n';
    }

    std::cout << "\nCHAR\n";

    for (int i = 0; i < countNumbers; ++i)
    {
        std::cout << static_cast<int>(genChar()) << '\n';
    }

    return 0;
}