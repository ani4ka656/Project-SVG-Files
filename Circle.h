#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "Shape.h"
class Circle : public Shape
{
private:
    int cx;
    int cy;
    int r;
    std::string colour;
public:
    Circle(int = 0, int = 0, int = 0, std::string = "", const std::string& = "circle");
    virtual std::string getShape() override
    {
        return "circle";
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



