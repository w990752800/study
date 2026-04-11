#include <iostream>

#include <cstdint>

// #define COUNT = 1000;

int main() {

    int32_t a = 100;
    uint8_t b = 5;

    #ifdef COUNT
        std::cout << "xxx" << std::endl;
    #endif
    

    return 0;
}