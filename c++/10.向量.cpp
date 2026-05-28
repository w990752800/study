
// 向量就是动态数组，长度可变的数组；

#include <iostream>

int main()
{

    // 初始化
    std::vector<int> i1;
    std::vector<int> i2;

    i1 = {1, 2, 3, 4};
    i2 = {1, 2, 3, 4};

    std::vector<std::string> s{"1", "2"};
    std::vector<float> b{true, false};

    // 添加元素
    s.push_back("333");

    for (int i = 0; i < 30; i++)
    {
        i1.push_back(i);
    };

    std::cout << i1.size() << std::endl;

    // 链表 迭代
    for(int i:i1) {
        std::cout << i << std::endl;
    };

    for(int i = 0; i < s.size(); i++) {
        std::cout << s[i] << std::endl; 
        std::cout << s.at(i) << std::endl; 
    };

    // 删除最后一个元素
    s.pop_back();

    // 获取最后一个元素
    int n = i2.back();

    // 迭代器，遍历
    for(auto iter = s.begin(); iter != s.end(); iter++){
        std::cout << *iter << std::endl;
    }

    return 0;
}
