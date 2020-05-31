#ifndef _SHAPES_H_
#define _SHAPES_H_
#include <vector>
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "FileManager.h"
#include <exception>
class Shapes
{
private:
    std::vector<Shape*> shapes;

    void copyData(const Shapes& other)
    {
        for(int i=0; i<other.shapes.size(); i++)
        {
            //shapes[i] = other.shapes[i];
            shapes.push_back(other.shapes[i]->clone());
        }
    }
    void deleteData()
    {
        for(int i=0; i<shapes.size(); i++)
            delete shapes[i];
    }
public:
    //friend class FileManager;
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
};
void Shapes::printShapes() const
{
    for (int i = 0; i < shapes.size(); i++)
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
        std::cerr<<"The File is empty!"<<std::endl;
        return false;
    }
    if(position < 0 || position >= max_position)
    {
        std::cerr<<"Not found! Figures positions are between 0 and "<<max_position-1<<std::endl;
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
    std::cout << "Erased a " << figure->getShape() << " (" << position << ")\n";
    delete figure;
}
void Shapes::saveShapes(std::ofstream& ofs) const
{
    for (int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->writeToFile(ofs);
    }

}
void Shapes::translateShape(const int& position, const int& vertical, const int& horizontal) const
{
    shapes[position - 1]->translate(vertical, horizontal);
    std::cout << "Translated " << position << "\n";
}
void Shapes::translateShapes(const int& vertical, const int& horizontal) const
{
    for (int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->translate(vertical, horizontal);
    }
    std::cout << "Translated all figures\n";

}
int Shapes::counter = 0;
#endif
