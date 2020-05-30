#ifndef _SHAPES_H_
#define _SHAPES_H_
#include <vector>
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "FileManager.h"

class Shapes
{
private:
    std::vector<Shape*> shapes;

    void copyData(const Shapes& other)
    {
        for(int i=0; i<other.shapes.size(); i++)
        {
            shapes[i] = other.shapes[i];
        }
    }
    void deleteData()
    {
        for(int i=0; i<shapes.size(); i++)
            delete shapes[i];
    }
public:
    friend class FileManager;
    static int counter;
    Shapes(){};
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
};
int Shapes::counter = 0;
#endif
