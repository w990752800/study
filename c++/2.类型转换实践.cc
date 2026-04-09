#include <iostream>
#include <cstdint>


int main() {

    float a = 1.1;
    float b = 2.2;
    float c = 3.3;

    auto result = (int)a + (int)b + (int)c;

    std::cout << result << std::endl;

    return 0;
}