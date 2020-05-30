#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "Shape.h"
class Rectangle : public Shape
{
private:
    int x;
    int y;
    int width;
    int height;
    std::string colour;
public:
    Rectangle(int = 0, int = 0, int = 0, int = 0, std::string = "", const std::string& = "rectangle");
    virtual std::string getShape() override
    {
        return "rectangle";
    }
    void print() const;
    virtual std::string combine()override;
    virtual void translate(const int ,const int) override;
    /* Point CoordinatesOfBottomLeftPoint()const override;
    Point CoordinatesOfBottomRightPoint()const override;
    Point CoordinatesOfTopLeftPoint()const override;
    Point CoordinatesOfTopRightPoint()const override;*/
    void writeToFile(std::ostream& os) override
    {
        std::string news = combine();
        os<<news;
    }

};
#endif
