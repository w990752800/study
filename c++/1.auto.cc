

#include <iostream>


int main() {

    auto a = 1;
    auto b = 1.0;
    auto c = 3.5f;
    auto d = true;
    auto e = 'e';
    auto f = "string";

    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;
    std::cout << typeid(c).name() << std::endl;
    std::cout << typeid(d).name() << std::endl;
    std::cout << typeid(e).name() << std::endl;
    std::cout << typeid(f).name() << std::endl;

    return 0;
}


