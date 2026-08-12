#include <iostream>

class Clock
{

public:
    int settime(int a = 0, int b = 0);
    int showtime();

private:
    int a, b;
    static std::string str;
};

std::string Clock::str = "xxxx";

int Clock::showtime() {
    std::cout << str << std::endl;
    return 0;
};


int main()
{
    Clock clk1;
    clk1.showtime();

    return 0;
}