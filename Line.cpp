#include "Line.h"
Line::Line(int x1, int y1, int x2, int y2, const std::string& name) : x1(x1), y1(y1), x2(x2), y2(y2), Shape(name)
{
    double value = Point(x1,y1).distanceToTheOther(Point(x2,y2));
    if (value<0)
    {
        value = 0;
    }
    pathLength = value;
}

std::string Line::getShape() const
{
    return "line";
}

void Line::print()const
{
    std::cout<<Shape::name<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<pathLength;
}

std::string Line::combine() const
{
    std::string result;
    result += getShape();
    result += " ";
    result += std::to_string(x1);
    result += " ";
    result += std::to_string(y1);
    result += " ";
    result += std::to_string(x2);
    result += " ";
    result += std::to_string(y2);
    result += " ";
    result += std::to_string(pathLength);
    result += "\n";
    return result;
}

void Line::translate(const int vertical, const int horizontal)
{
    x1 += vertical;
    x2 += vertical;
    y1 += horizontal;
    y2 += horizontal;
}

void Line::writeToFile(std::ostream& os)
{
    std::string news = combine();
    os<<news;
}

Shape* Line::clone() const
{
    return new Line(*this);
}
