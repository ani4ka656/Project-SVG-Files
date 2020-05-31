#include "FileManager.h"
#include <cstdlib>

void FileManager::removeSpace(const std::string &str, std::string *word)
{
    int counterr = 0;
    for (int x = 0; x < str.length(); x++)
    {
        if (str[x] == ' ' && str[x-1] != '=' && str[x+1] != '=')
        {
            counterr++;
        }
        else if(str[x] != ' ' && str[x] != '"')
        {
            word[counterr] += str[x];
        }
    }
}

void FileManager::start()
{
    std::string userInput;
    while (true)
    {
        std::cout << "> ";
        getline(std::cin, userInput);
        std::string parts[7] = {};
        removeSpace(userInput, parts);
        std::string operation = parts[0];
        if (operation == "open")
        {
            if(checkFileInput(parts[1]))
                open(parts[1]);
            std::cout<<"You are entering wrong file extension, it must be (.svg)\n";
        }
        else if (operation == "create")
        {
            create(parts);

        }
        else if (operation == "erase")
        {
            eraseIt(atoi(parts[1].c_str()));
        }
        else if (operation == "translate")
        {
            translate(parts);
        }
        else if (operation == "print")
        {
            print();
        }
        else if (operation == "save")
        {
            save();
        }
        else if (operation == "saveas")
        {
            if(checkFileInput(parts[1]))
                saveAs(parts[1]);
            std::cout<<"You are entering wrong file extension, it must be (.svg)\n";
        }
        else if (operation == "exit")
        {
            std::cout << "Exit\n";
            RealFileName = "";
            Allshapes.clearShapes();
            Shapes::counter = 0;
            return;
        }
        else if (operation == "close")
        {
            if (RealFileName == "")
            {
                std::cout << "There is no opened file!\n";
            }
            std::cout << "Closed current file\n";
            RealFileName = "";
            Allshapes.clearShapes();
            //Allshapes.shapes.clear();
            Shapes::counter = 0;
        }
        /*else if (operation == "within")
        {
            within(parts);
        }*/
        else if (operation == "help")
        {
            printHelp();
        }
        else
        {
            std::cout << "There is no such a command!\n";
            printHelp();
        }
    }
}

void FileManager::loadShapes(std::istream& fin)
{
    std::string myText;
    while (getline(fin, myText))
    {
        std::string attr[6] = {};
        int cntr = 0;
        removeSpace(myText, attr);
        if (attr[0] == "line")
        {
            Allshapes.addShape(new Line(atoi(attr[1].c_str()), atoi(attr[2].c_str()), atoi(attr[3].c_str()), atoi(attr[4].c_str())));
        }
        else if (attr[0] == "rectangle")
        {
            Allshapes.addShape(new Rectangle(atoi(attr[1].c_str()), atoi(attr[2].c_str()), atoi(attr[3].c_str()), atoi(attr[4].c_str()), attr[5]));

        }
        else if (attr[0] == "circle")
        {
            Allshapes.addShape(new Circle(atoi(attr[1].c_str()), atoi(attr[2].c_str()), atoi(attr[3].c_str()), attr[4]));
        }
        Shapes::counter++;

    }
}
bool FileManager::checkFileInput(const std::string& fileName) const
{
    bool check = false;

    std::string word;
    for (int x = 0; x < fileName.length(); x++)
    {
        if (fileName[x] == '.')
        {
            check =true;
        }
        if(check)
        {
            word += fileName[x];
        }
    }
    //std::cout<<word;
    if(word == ".svg")
        return 1;
    return 0;
}
void FileManager::open(const std::string& fileName)
{
    Shapes::counter = 0;
    RealFileName = fileName;
    std::ifstream fin(RealFileName.c_str());
    if(!fin)
    {
        fin.close();
        std::cout<<"File is empty"<<std::endl;
        std::ofstream os(RealFileName.c_str());
        std::cout<<"Please add some figures using create"<<std::endl;
        os.close();
        return;
    }
    else
    {
        loadShapes(fin);
        std::cout << "Successfully opened " << RealFileName << "\n";
        fin.close();
        print();
    }
}

void FileManager::create(std::string *parts)
{
    if (parts[1] == "line")
    {
        Allshapes.addShape(new Line(atoi(parts[2].c_str()), atoi(parts[3].c_str()), atoi(parts[4].c_str()), atoi(parts[5].c_str())));
    }
    else if (parts[1] == "rectangle")
    {
        Allshapes.addShape(new Rectangle(atoi(parts[2].c_str()), atoi(parts[3].c_str()), atoi(parts[4].c_str()), atoi(parts[5].c_str()), parts[6]));
    }
    else if (parts[1] == "circle")
    {
        Allshapes.addShape(new Circle(atoi(parts[2].c_str()), atoi(parts[3].c_str()), atoi(parts[4].c_str()), parts[5]));
    }
    else
    {
        std::cout << "Check if you have made a mistake in the input of the shape, the shapes that are available for now are line/rectangle/circle\n";
    }
    Shapes::counter++;
    print();
    std::cout << "Successfully created " << parts[1] << " (" << Shapes::counter << ")" << "\n";

}

void FileManager::print() const
{
    Allshapes.printShapes();
}

void FileManager::eraseIt(const int& position)
{
    Allshapes.eraseShape(position);
}

void FileManager::save() const
{
    if(RealFileName == "")
    {
        std::cout << "There is no opened file!\n";
        return;
    }
    saveAs(RealFileName.c_str());
}

void FileManager::saveAs(const std::string &fileName) const
{
    std::ofstream ofs(fileName, std::ios::out| std::ios::trunc);
    if(!ofs)
        std::cout<<"Failed to save to file"<<std::endl;
    Allshapes.saveShapes(ofs);
    ofs.close();
    std::cout << "Successfully saved " << fileName << " \n";
}
int getNum(const std::string &str)
{
    std::string word;
    bool check = false;
    for (int x = 0; x < str.length(); x++)
    {
        if (str[x] == '=')
        {
            check = true;
        }
        if(str[x] != ' ' && str[x]!= '=' )
        {
            if(check)
                word += str[x];
        }
    }
    int num = 0;
    num = atoi(word.c_str());
    return num;
}

void FileManager::translate(std::string* parts) const
{

    int vertical = getNum(parts[2]);
    int horizontal = getNum(parts[1]);
    if (parts[3]=="")

        Allshapes.translateShapes(vertical, horizontal);
    else
    {
        int position = atoi(parts[3].c_str());
        Allshapes.translateShape(position, vertical, horizontal);
    }

}
/*bool ItIsInsideRectangle(Rectangle *rect, const Shape* shape)
{

    if(shape->getShape() == "rectangle")
    {
        bool f1 = rect->CoordinatesOfBottomLeftPoint() <= shape->CoordinatesOfBottomLeftPoint();
        bool f2 = rect->CoordinatesOfTopRightPoint() >= shape->CoordinatesOfBottomRightPoint();
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
    } /*selse if(shape->getShape() == "line")
     {
        bool f1 = rect->CoordinatesOfTopLeftPoint() >= Point(shape->getX1(),shape->getY1()) && rect.CoordinatesOfBottomLeftPoint() <= Point(shape->getX1(),shape->getY1());
        bool f2 = rect->CoordinatesOfBottomRightPoint() >=Point(shape->getX2(),shape->getY2()) && rect.CoordinatesOfTopRightPoint() >=Point(shape->getX2(),shape->getY2());
        if(f1 && f2)
            return true;
        return false;
    }/*/
/*}
void FileManager::within(std::string* parts)
{
    Shapes withIn;
    int counter = 0;
    if (parts[1]== "rectangle")
    {
        Rectangle* rect = new Rectangle(atoi(parts[2].c_str()), atoi(parts[3].c_str()), atoi(parts[4].c_str()), atoi(parts[5].c_str()));
        for (int i = 0; i < Allshapes.shapes.size(); i++)
        {

            if (ItIsInsideRectangle(rect, Allshapes.shapes[i]))
            {
                withIn.addShape(rect);
                counter++;
            }
        }
        delete rect;
    }

    if (counter == 0)
    {
        std::cout << "No shapes are located within ";
        std::cout << "\n";
    }
    else
    {
        withIn.printShapes();
    }
}*/
void FileManager::printHelp() const
{
    std::cout << "Commands available:The following commands are supported:\n";
    std::cout << "open <file> - opens <file>\n";
    std::cout << "close - closes the currently open file\n";
    std::cout << "save - saves the currently open file\n";
    std::cout << "saveas <file> - saves the currently open file in <file>\n";
    std::cout << "help - prints this information\n";
    std::cout << "exit - exists the program\n";
    std::cout << "print - prints all the information for all figures\n";
    std::cout << "create <rectangle/circle/line> - creates a new figure \n";
    std::cout << "erase <n> - erases figure with number <n>\n";
    std::cout << "translate {<index>} - translates the figure with number <n> or all of them if <n> is not initialized\n";
    std::cout << "within <rectangle/circle> - prints all the figures that are in a region\n";
}


