#ifndef _LINE_H_
#define _LINE_H_
#include "Shape.h"
class Line : public Shape
{
private:
    int x1;
    int x2;
    int y1;
    int y2;
    int pathLength;
public:
    Line(int = 0, int = 0, int = 0, int = 0, const std::string& = "line");
    virtual std::string getShape() const override;
    void print() const;
    virtual std::string combine() const override;
    virtual void translate(const int,const int) override;
    virtual void writeToFile(std::ostream&) override;
    virtual Shape* clone() const override;

};
#endif
