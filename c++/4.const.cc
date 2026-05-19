#include <iostream>


int main() {
    
    const size_t LEN = 4;

    int array_int[LEN];

    array_int[0] = 1;


    array_int[0] = 2;
    std::cout << array_int[0] << std::endl;


    return 0;
}