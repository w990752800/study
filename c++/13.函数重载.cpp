#include <iostream>

// 函数重载
// 函数名称一样，参数不一样
// 函数名 + 参数 =》 作为函数的唯一标识

int add(int a, int b) {
    std::cout << "int a, int b => a+b" << std::endl;
    return a + b;
}

int add(float a, float b) {
    std::cout << "float a, float b" << std::endl;
    return a + b;
}

std::string add(std::string &a, std::string &b) {
    std::cout << "string a, string b" << std::endl;
    return a + b;
}

int main() {

    std::string a = "xxx";
    std::string b = "yyy";

    std::string result = add(a,b);
    
    std::cout << result << std::endl;

    return 0;
}