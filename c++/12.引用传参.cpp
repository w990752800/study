
#include <iostream>

// 引用传参，减少变量的复制，减少指针的使用
int copy_ref(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
    return 0;
}

int main()
{
    int x = 10;
    int y = 20;
    copy_ref(x, y);

    std::cout << x << " " << y << std::endl;
    return 0;
}