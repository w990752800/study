
#include <iostream>

int main() {

    // if
    int a = 10;
    int b = 20;
    if(a > b) {
        std::cout << "a大于b" << std::endl;
    } else {
        std::cout << "b大于a" << std::endl;
    };

    
    if(a < b) {
        std::cout << "1" << std::endl;
    } else if(a == b) {
        std::cout << "2" << std::endl;
    } else {
        std::cout << "3" << std::endl;
    }

    return 0;
}


