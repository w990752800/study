#include <iostream>

class Clock {

    public:
    Clock(int a = 0, int b = 0);

    private:
    int showtime();
    int settime(int a, int b);
};

int Clock::showtime() {
    return 0;
}

int Clock::settime(int a, int b) {
    std::cout << a << b << std::endl;
    return 0;
}



Clock::~Clock() {
    std::cout << "函数销毁的时候调用" << std::endl;
}

int main() {


    return 0;
}