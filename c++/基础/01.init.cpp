
/**
 * 编译
 * g++ 01.init.cpp -o 01.init
 * 
 * 执行完毕之后,执行下面语句输出上一个程序执行后的返回值
 * echo $? 
 * 
 */
#include <iostream>

int main() {
    std::cout << "Hello world" << std::endl;
    return 12;
}