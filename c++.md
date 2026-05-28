1. 打印hello world
```c++
#include <iostream>
int main() {
    std::cout << "Hello world" << std::endl;
    return 0;
}
```

2. 变量
```c++
#include <iostream>
int main() {

    int i = 1;
    double PI = 3.14;
    float f = 0.3;
    bool isRight = false;
    char c = 'c';
    std::string str = "wnf";
    std::string str1 = "str1";

    // 字符串操作
    std::cout << str.length() << std::endl;
    std::cout << str.size() << std::endl;
    std::cout << str + str1 << std::endl;

    return 0;
}
```

3. 用户输入
```c++
#include <iostream>
int main() {
    
    std::string s = "";
    std::cin >> s;
    std::cout << s << std::endl;
    
    return 0;
}
```

4. if
```c++
#include <iostream>
int main() {
    
    int a = 10;
    int b = 20;

    if(a > b) {
        std::cout << "1" << std::endl;
    } else {
        std::cout << "2" << std::endl;
    }

    return 0;
}
```

5.for
```c++
#include <iostream>
int main() {
    for(int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }
    return 0;
}
```

6. 函数

注意：不用用一些特殊的名称，例如： todo

```c++
#include <iostream>

void my_do(); // 声明

int main() {
    my_do(); // 执行
    return 0;
}

// 定义
void my_do() {
    std::cout << "do" << std::endl;
}
```

7. 引用
引用就是变量的一个别名；引用必须初始化；一旦绑定了一个变量，就不能绑定另一个变量了；
```c++
#include <iostream>

int main() {
    int a = 10;
    int &b = a;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << &a << std::endl;
    std::cout << &b << std::endl;

    return 0;
}
```

8. 命名空间
```c++
#include <iostream>

// namespace ns1 {
//     int val(){
//         return 6;
//     }
// }

// int main() {
//     int val = ns1::val();
//     return 0;
// }

namespace ns1 {
    int val() {
        return 5;
    }
}

using namespace ns1;
int main() {

    int res = val();

    std::cout << res << std::endl;
    return 0;
}


```

9. 数组
```c++
#include <iostream>
int main() {
    std::array<int, 5> marks = {1,2,3,4,5};
    std::cout << marks[0] << std::endl;
    return 0;
}
```

10. 向量
```c++
#include <iostream>

int main() {

    // 向量就是一个动态数组
    // 创建向量
    std::vector<std::string> s{"1","2"};

    // 追加元素
    s.push_back("3");

    // 向量迭代
    for(int i:s) {
        std::cout << i << std::endl;
    }

    // 删除最后一个元素
    s.pop_back();

    // 获取最后一个元素
    std::string s_back = s.back();

    // 是否为空
    if(s.empty() == 0) {
        std::cout << "空向量"  << std::endl;
    }

    // 迭代器
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        std::cout << *iter << std::endl;
    }

    return 0;
}

```

11. 错误处理
```c++

#include <iostream>
#include <stdexcept>

int main() {

    while(1) {

        std::string s1;
        std::string s2;

        std::cin >> s1 >> s2;

        try {
            if(s1 == s2) {
                throw std::runtime_error("xxx");
            }
        } catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
            break;
        }

    }

    return 0;
}


```