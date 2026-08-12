
#include <iostream>

class Point
{
private:
    float x, y;
public:
    Point(/* args */);
    Point(float xx, float yy);
    ~Point();
    friend int distance(Point &p1, Point &p2);
};

Point::Point(/* args */)
{
    this->x = 0;
    this->y = 0;
}

Point::Point(float xx, float yy) {
    this->x = xx;
    this->y = yy;
}

int distance(Point &p1, Point &p2) {
    float result = p1.x - p2.x;
    std::cout << result << std::endl;
    return 0;
}



Point::~Point()
{
}



int main() {

    Point p1;
    Point p2(4,2);

    distance(p1, p2);

    return 0;
}

