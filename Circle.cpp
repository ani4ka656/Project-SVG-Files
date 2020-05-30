#include "Circle.h"
Circle::Circle(int cx, int cy, int r, std::string colourNew, const std::string& name) : cx(cx), cy(cy), r(r), Shape(name)
{
    if(colourNew == "") colour = "no colour";
        colour = colourNew;
}

void Circle::print()const
{
    std::cout<<Shape::name<<" "<<cx<<" "<<cy<<" "<<r<<" "<<colour<<std::endl;;
}
std::string Circle::combine()
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
void Circle::translate(const int vertical ,const int horizontal)
{
    cx += vertical;
    cy += horizontal;

}

/*Point Circle::CoordinatesOfTopLeftPoint()const
{
	return Point(x,y+width)
}

Point Circle::CoordinatesOfBottomLeftPoint()const
{
	return Point(x,y);
}

Point Circle::CoordinatesOfTopRightPoint()const
{
	return Point(x+width,y+height);
}

Point Circle::CoordinatesOfBottomRightPoint() const
{
	return Point(x+width,y);
}*/
