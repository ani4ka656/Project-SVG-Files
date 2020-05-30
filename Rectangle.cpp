#include "Rectangle.h"
Rectangle::Rectangle(int x, int y, int width, int height, std::string colourNew, const std::string& name) : x(x), y(y), width(width), height(height), Shape(name)
{
    if(colourNew == "") colour = "no colour";
        colour = colourNew;
}

void Rectangle::print()const
{
    std::cout<<Shape::name<<" "<<x<<" "<<y<<" "<<width<<" "<<height<<" "<<colour<<std::endl;;
}
std::string Rectangle::combine()
{
    std::string result;
    result += getShape();
        result += " ";
        result += std::to_string(x);
        result += " ";
        result += std::to_string(y);
        result += " ";
        result += std::to_string(width);
        result += " ";
        result += std::to_string(height);
        result += " ";
        result += colour;
       result += "\n";
return result;

}
void Rectangle::translate(const int vertical ,const int horizontal)
{
    x += vertical;
    y += horizontal;

}

/*Point Rectangle::CoordinatesOfTopLeftPoint()const
{
	return Point(x,y+width)
}

Point Rectangle::CoordinatesOfBottomLeftPoint()const
{
	return Point(x,y);
}

Point Rectangle::CoordinatesOfTopRightPoint()const
{
	return Point(x+width,y+height);
}

Point Rectangle::CoordinatesOfBottomRightPoint() const
{
	return Point(x+width,y);
}*/
