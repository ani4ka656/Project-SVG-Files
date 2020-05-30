#ifndef SHAPE_H_
#define SHAPE_H_
#include<string>
#include<iostream>
#include "Point.h"
class Shape
{
protected:
	std::string name;
public:
    //Shape(){};
    Shape(const std::string& name) : name(name){};
    virtual std::string getShape() { return 0;  }
    virtual void writeToFile(std::ostream &os) =0;
    virtual std::string combine() {return 0;}
    virtual void translate(const int, const int)=0;
	/*virtual Point CoordinatesOfBottomLeftPoint()const { return 0;  }
    virtual Point CoordinatesOfBottomRightPoint()const { return 0;  }
    virtual Point CoordinatesOfTopLeftPoint()const { return 0;  }
	virtual Point CoordinatesOfTopRightPoint()const { return 0;  }*/
};
#endif
