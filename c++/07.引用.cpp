

#include <iostream>

int main() {

    // 引用就是一个变量的别名，引用必须初始化，并且一旦绑定到一个变量，就不能再绑定到另一个变量了。
    int i = 1;
    int& ri = i;

    std::cout << i << std::endl;
    std::cout << ri << std::endl;

    std::cout << &i << std::endl;
    std::cout << &ri << std::endl;

    return 0;
}


