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

void Line::print()const
{
    std::cout<<Shape::name<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<pathLength;
}
std::string Line::combine()
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
void Line::setX(const int vertical) {x1 = x1 +vertical; x2+=vertical;}
void Line::setY(const int horizontal) {y1 += horizontal; y2+=horizontal;}
void Line::translate(const int vertical ,const int horizontal)
{
   setX(vertical);
   setY(horizontal);

}
