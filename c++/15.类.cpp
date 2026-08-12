#include <iostream>

// 类
class Clock
{
public:
    int settime(int h = 0, int m = 0, int s = 0);
    int showtime();

private:
    int hour, minte, soure;
};

int Clock::settime(int h, int m, int s)
{
    hour = h;
    minte = m;
    soure = s;
    return 0;
}

int Clock::showtime()
{
    std::cout << "hour=>" << hour << " " << "minte=>" << minte << " " << "soute=>" << soure << " " << std::endl;

    return 0;
}

int main()
{

    Clock clock;

    clock.settime();
    clock.showtime();

    clock.settime(10, 20, 30);
    clock.showtime();

    return 0;
}