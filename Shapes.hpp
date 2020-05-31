#ifndef _SHAPES_H_
#define _SHAPES_H_
#include <vector>
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
//#include "FileManager.h"
#include <exception>
class Shapes
{
private:
    std::vector<Shape*> shapes;

    void copyData(const Shapes& other)
    {
        for(int i = 0;i < other.shapes.size();i++)
        {
            //shapes[i] = other.shapes[i];
            shapes.push_back(other.shapes[i]->clone());
        }
    }
    void deleteData()
    {
        for(int i = 0;i<shapes.size();i++)
            delete shapes[i];
    }
public:
    static int counter;
    Shapes() {};
    Shapes(const Shapes& other)
    {
        copyData(other);
    }

    Shapes& operator=(const Shapes& other)
    {
        if(this != &other)
        {
            deleteData();
            copyData(other);
        }
        return *this;
    }
    ~Shapes()
    {
        deleteData();
    }
    void addShape(Shape*);
    bool check_position(const int&, const int&) const;
    void eraseShape(const int&);
    void printShapes() const;
    void translateShapes(const int&, const int&) const;
    void saveShapes(std::ofstream&) const;
    void translateShape(const int&, const int&, const int&) const;
    void clearShapes();
    bool ItIsInsideRectangle(Shape*, const Shape*);
    bool ItIsInsideCircle(Shape*, const Shape*);
    void withinShapes(Shape*, Shapes, int&, const std::string&);
};

void Shapes::printShapes() const
{
    if(shapes.size() == 0) std::cout << "No figures!" << std::endl;
    for (int i = 0;i < shapes.size();i++)
    {
        std::string ans = shapes[i]->combine();
        std::cout << i + 1 << ". " << ans;
    }
}

void Shapes::clearShapes()
{
    shapes.clear();
}

void Shapes::addShape(Shape* shape)
{
    shapes.push_back(shape->clone());
}

bool Shapes::check_position(const int& position, const int& max_position) const
{
    if(max_position == 0)
    {
        std::cerr << "The File is empty!" << std::endl;
        return false;
    }
    if(position < 0 || position >= max_position)
    {
        std::cerr << "Not found! Figures positions are between 0 and " << max_position-1 << std::endl;
        std::cout << "There is no figure number " << position + 1 << std::endl;
        return false;
    }
    return true;
}

void Shapes::eraseShape(const int& position)
{
    if(!check_position(position - 1, shapes.size()))
        return;
    Shape* figure = shapes[position - 1];
    shapes.erase(shapes.begin() + position - 1);
    Shapes::counter--;
    std::cout << "Erased a " << figure->getShape() << " (" << position << ")" << std::endl;
    delete figure;
}

void Shapes::saveShapes(std::ofstream& ofs) const
{
    for (int i = 0;i < shapes.size();i++)
    {
        shapes[i]->writeToFile(ofs);
    }

}
void Shapes::translateShape(const int& position, const int& vertical, const int& horizontal) const
{
    shapes[position - 1]->translate(vertical, horizontal);
    std::cout << "Translated " << position << std::endl;
}

void Shapes::translateShapes(const int& vertical, const int& horizontal) const
{
    for (int i = 0;i < shapes.size();i++)
    {
        shapes[i]->translate(vertical, horizontal);
    }
    std::cout << "Translated all figures" << std::endl;

}

/*bool Shapes::ItIsInsideCircle(Shape* circle, const Shape* shape)
{

    if(shape->getShape() == "rectangle")
    {
        bool f1 = Point(circle->CoordinatesOfBottomRightPoint().distanceToTheOther(shape->CoordinatesOfBottomLeftPoint()),0)>=circle->CoordinatesOfTopLeftPoint();
        bool f2 = Point(circle->CoordinatesOfBottomRightPoint().distanceToTheOther(shape->CoordinatesOfBottomRightPoint()),0)>=circle->CoordinatesOfTopLeftPoint();
        bool f3 = Point(circle->CoordinatesOfBottomRightPoint().distanceToTheOther(shape->CoordinatesOfTopLeftPoint()),0)>=circle->CoordinatesOfTopLeftPoint();
        bool f4 = Point(circle->CoordinatesOfBottomRightPoint().distanceToTheOther(shape->CoordinatesOfTopRightPoint()),0)>=circle->CoordinatesOfTopLeftPoint();
        if(f1 && f2 && f3 && f4)
            return true;
        return false;
    }
    else if(shape->getShape() == "circle")
    {
        bool f1 = circle->CoordinatesOfBottomLeftPoint()>= shape->CoordinatesOfBottomLeftPoint();
        bool f2 = circle->CoordinatesOfTopRightPoint() >=  shape->CoordinatesOfTopRightPoint();
        if(f1 && f2 )
            return true;
        return false;
    }
    else if(shape->getShape() == "line")
    {
        std::cout<<"Here";
        bool f1 = Point(circle->CoordinatesOfBottomRightPoint().distanceToTheOther(shape->CoordinatesOfTopLeftPoint()), 0)>=circle->CoordinatesOfTopLeftPoint();
        bool f4 = Point(circle->CoordinatesOfBottomRightPoint().distanceToTheOther(shape->CoordinatesOfTopRightPoint()), 0)>=circle->CoordinatesOfTopLeftPoint();
        if(f1 && f4 )
            return true;
        return false;
    }
}
*/
bool Shapes::ItIsInsideRectangle(Shape* rect, const Shape* shape)
{

    if(shape->getShape() == "rectangle")
    {
        bool f1 = rect->CoordinatesOfBottomLeftPoint() <= shape->CoordinatesOfBottomLeftPoint();
        bool f2 = rect->CoordinatesOfTopRightPoint() >= shape->CoordinatesOfTopRightPoint();
        if(f1 && f2 )
            return true;
        return false;
    }
    else if(shape->getShape() == "circle")
    {
        bool f1 = rect->CoordinatesOfTopRightPoint() >= shape->CoordinatesOfTopRightPoint();
        bool f2 = rect->CoordinatesOfBottomLeftPoint() <=shape->CoordinatesOfBottomLeftPoint();
        if(f1 && f2 )
            return true;
        return false;
    }
    else if(shape->getShape() == "line")
    {
        //std::cout<<"Here";
        bool f1 = rect->CoordinatesOfTopRightPoint() >= shape->CoordinatesOfTopRightPoint();
        //bool f2 = rect->CoordinatesOfTopLeftPoint() <= shape->CoordinatesOfTopLeftPoint();
        //std::cout<<"f1"<<f1;
        // std::cout<<"f2"<<f2;
        // bool f3 = rect->CoordinatesOfBottomRightPoint() <= shape->CoordinatesOfTopRightPoint();
        bool f4 = rect->CoordinatesOfBottomLeftPoint() <= shape->CoordinatesOfTopLeftPoint();
        if(f1 && f4 /*&& f3 && f4*/)
            return true;
        return false;
    }
}

void Shapes::withinShapes(Shape* shape, Shapes withIn,int& counter, const std::string& str)
{
    for (int i = 0;i < shapes.size();i++)
    {
        if(str == "rectangle")
        {
            if (ItIsInsideRectangle(shape, shapes[i]))
            {
                withIn.addShape(shapes[i]);
                counter++;
            }
        }
        /*else if (str == "circle")
        {
            if (ItIsInsideCircle(shape, shapes[i]))
            {
                withIn.addShape(shapes[i]);
                counter++;
            }
        }*/
    }
    std::cout<<counter;
    if (counter == 0)
    {
        std::cout << "No shapes are located within " << std::endl;
    }
    else
    {
        withIn.printShapes();
    }
}

int Shapes::counter = 0;
#endif
