
#include <iostream>

class Clock {

    public:
    int settime(int a = 0, int b = 0);
    int showtime();

    private:
    int a, b;

};

int Clock::settime(int a, int b) {
    this->a = a;
    this->b = b;
    return 0;
}

int main() {

    Clock clock;

    return 0;
}


