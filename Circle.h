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
    virtual std::string getShape() const override;
    void print() const;
    virtual std::string combine() const override;
    virtual void translate(const int,const int) override;
    virtual void writeToFile(std::ostream&) override;
    virtual Shape* clone() const override;
    virtual Point CoordinatesOfBottomLeftPoint() const override;
    virtual Point CoordinatesOfBottomRightPoint() const override;
    virtual Point CoordinatesOfTopRightPoint() const override;
    virtual Point CoordinatesOfTopLeftPoint() const override;
};
#endif



