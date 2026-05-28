

#include <iostream>

int main() {

    // int
    int a = 1;
    int b = 2;
    int c = a + b;
    std::cout << "a => " << a << std::endl;
    std::cout << "b => " << b << std::endl;
    std::cout << "c => " << c << std::endl;

    // float
    float d = 0.2;
    float e = 4.2;
    float f = e - d;
    std::cout << f << std::endl;

    // double
    double PI = 3.1415926;
    
    // bool
    bool isRight = false;

    // char
    char cc = 'cc';

    // string
    std::string s = "string";
    std::string s1 = "s1";

    // 字符串操作
    std::cout << s.length() << std::endl;
    std::cout << s.size() << std::endl;
    std::cout << s.empty() << std::endl;
    std::cout << s + s1 << std::endl;

    return 0;
}


