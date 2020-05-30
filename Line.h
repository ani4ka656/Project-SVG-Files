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
    void setX(const int);
    void setY(const int);
    Line(int = 0, int = 0, int = 0, int = 0, const std::string& = "line");
    virtual std::string getShape() override
    {
        return "line";
    }
    void print() const;
    virtual std::string combine() override;
    virtual void writeToFile(std::ostream& os) override
    {
        std::string news = combine();
        os<<news;
    }
    virtual void translate(const int ,const int) override;

};
#endif
