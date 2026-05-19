
#include <iostream>
#include <cstdint>

int main() {

    uint32_t a = 10;

    uint32_t *prt;

    prt = nullptr;

    prt = &a;

    std::cout << "a的值" << &a << std::endl;



    return 0;
}