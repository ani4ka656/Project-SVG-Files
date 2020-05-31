#include "Circle.h"
Circle::Circle(int cx, int cy, int r, std::string colourNew, const std::string& name) : cx(cx), cy(cy), r(r), Shape(name)
{
    if(colourNew == "")
        colour = "no colour";
    colour = colourNew;
}

std::string Circle::getShape() const
{
    return "circle";
}

void Circle::print()const
{
    std::cout<<Shape::name<<" "<<cx<<" "<<cy<<" "<<r<<" "<<colour<<std::endl;;
}

std::string Circle::combine() const
{
    std::string result;
    result += getShape();
    result += " ";
    result += std::to_string(cx);
    result += " ";
    result += std::to_string(cy);
    result += " ";
    result += std::to_string(r);
    result += " ";
    result += colour;
    result += "\n";
    return result;

}

void Circle::translate(const int vertical,const int horizontal)
{
    cx += vertical;
    cy += horizontal;
}

void Circle::writeToFile(std::ostream& os)
{
    std::string news = combine();
    os<<news;
}

Shape* Circle::clone() const
{
    return new Circle(*this);
}

Point Circle::CoordinatesOfTopRightPoint() const
{
    return Point(cx+r,cy+r);
}

Point Circle::CoordinatesOfBottomLeftPoint() const
{
    return Point(cx-r,cy-r);
}

