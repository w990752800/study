#include <iostream>

int add(int a = 1, int b = 10) {
    return a + b;
}

int main() {
    int result = add();

    std::cout << result << std::endl;
    return 0;
}