#ifndef Point_H_
#define Point_H_
#include<math.h>
class Point
{
private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    bool operator<=(const Point& other)
    {
        if(x<=other.x && y<=other.y)
            return 1;
        return 0;
    }
    bool operator>=(const Point& other)
    {
        if(x>=other.x && y>=other.y)
            return 1;
        return 0;
    }
    double distanceToTheOther(const Point& other)
    {
        int newX = this->x - other.x;
        int newY = this->y - other.y;
        return sqrt(newX*newX + newY*newY);
    }
};
#endif
