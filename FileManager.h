#ifndef _FILEMANAGER_H_
#define _FILEMANAGER_H_
#include <fstream>
#include "Shapes.hpp"

class FileManager
{
private:

    std::string RealFileName;
    Shapes Allshapes;
    void loadShapes(std::istream&);
    void create(std::string*);
    void open(const std::string&);
    void eraseIt(const int&);
    void saveAs(const std::string&) const;
    void save() const;
    void print() const;
    void translate(std::string*) const;
    //void within(std::string*);
    void printHelp()const;
    void removeSpace(const std::string&, std::string*);
    bool checkFileInput(const std::string&) const;
public:
    void start();
    void tri();
};

#endif
