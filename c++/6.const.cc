

#include <iostream>

#include <cstdint>

int main() {

    const int8_t a = 8;

    std::cout << static_cast<int>(a) << std::endl;

    int b = 10;

    std::cout << b << std::endl;

    return 0;
}