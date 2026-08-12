#include <iostream>

class Clock
{
public:
    Clock(int h = 0, int m = 0, int s = 0);
    int showtime();

private:
    int hour, minute, second;
};

Clock::Clock(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

int Clock::showtime()
{
    std::cout << hour << minute << second << std::endl;
    return 0;
}

int main()
{
    Clock clock;
    clock.showtime();

    Clock clock1(1,2,3);
    clock1.showtime();
    return 0;
}