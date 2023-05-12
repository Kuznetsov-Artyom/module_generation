#include <iostream>
#include <limits>
#include <string>

#include "genRandData.hpp"

template <typename T>
void testType(int countValues = 1) {
  if (genRandData::is_integral_t<T>::value) {
    std::cout << "integer type\n";
  } else if (genRandData::is_float_point_t<T>::value) {
    std::cout << "float point type\n";
  } else if (genRandData::is_char_t<T>::value) {
    std::cout << "char type\n";
  } else {
    std::cout << "undefined type\n";
    return;
  }

  genRandData::Generator<T> generator(std::numeric_limits<T>::min(),
                                      std::numeric_limits<T>::max());

  for (int i = 0; i < countValues; ++i) {
    std::cout << generator() << '\n';
  }

  std::cout << '\n';
}

int main(int argc, char* argv[], char** env) {
  if (argc != 2) {
    return EXIT_FAILURE;
  }

  int countValue = std::stoi(std::string(argv[1]).c_str());

  testType<char>(countValue);
  testType<int8_t>(countValue);
  testType<uint8_t>(countValue);

  testType<signed int>(countValue);
  testType<int32_t>(countValue);
  testType<uint32_t>(countValue);

  testType<signed short>(countValue);
  testType<int16_t>(countValue);
  testType<uint16_t>(countValue);

  testType<signed long>(countValue);
  testType<long>(countValue);
  testType<unsigned long>(countValue);

  testType<signed long long>(countValue);
  testType<int64_t>(countValue);
  testType<uint64_t>(countValue);

  testType<float>(countValue);
  testType<double>(countValue);
  testType<long double>(countValue);

  return EXIT_SUCCESS;
}