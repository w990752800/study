
#include <iostream>
// // 定义命名空间
// namespace ns1 {
//     int val() {
//         return 5;
//     }
// }

// int main() {

//     int val = ns1::val();
//     std::cout << val << std::endl;

//     return 0;
// }

namespace ns1 {
    int val() {
        return 6;
    }
}

using namespace ns1;
int main() {
    std::cout << val() << std::endl;
    return 0;
}