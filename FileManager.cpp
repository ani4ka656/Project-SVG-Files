#include "FileManager.h"
#include<exception>
#include <cstdlib>
#include<typeinfo>

void FileManager::removeSpace(const std::string &str, std::string *word)
{
    int counterr =0;
    for (int x = 0; x<str.length(); x++)
    {
        if (str[x] == ' ')
        {
            counterr++;
        }
        if(str[x] != ' ')
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
            open(parts[1]);
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
            saveAs(parts[1]);
        }
        else if (operation == "exit")
        {
            std::cout << "Exit\n";
            RealFileName = "";
            Allshapes.shapes.clear();
            Shapes::counter = 0;
            return;
        }
        else if (operation == "close")
        {
            if (this->RealFileName == "")
            {
                std::cout << "There is no opened file!\n";
                //continue;
            }
            std::cout << "Closed current file\n";
            RealFileName = "";
            Allshapes.shapes.clear();
            Shapes::counter = 0;
        }
        //else if (operation == "within")
        // {
//            within(parts);
        //}
        else if (operation == "help")
        {
            printHelp();
        }
    }
}
void FileManager::loadShapes(std::istream&fin)
{
    std::string myText;
    while (getline(fin, myText))
    {
        std::string attr[6]= {};
        int cntr = 0;
        removeSpace(myText, attr);
        //Shape* temp;
        if (attr[0] == "line")
        {
            // temp = new Line(atoi(attr[1].c_str()), atoi(attr[2].c_str()), atoi(attr[3].c_str()), atoi(attr[4].c_str()));
            Allshapes.shapes.push_back(new Line(atoi(attr[1].c_str()), atoi(attr[2].c_str()), atoi(attr[3].c_str()), atoi(attr[4].c_str())));
        }
        else if (attr[0] == "rectangle")
        {
            //temp = new Rectangle(atoi(attr[1].c_str()), atoi(attr[2].c_str()), atoi(attr[3].c_str()), atoi(attr[4].c_str()), attr[5]);
            Allshapes.shapes.push_back(new Rectangle(atoi(attr[1].c_str()), atoi(attr[2].c_str()), atoi(attr[3].c_str()), atoi(attr[4].c_str()), attr[5]));
        }
        else if (attr[0] == "circle")
        {
            //temp = new Rectangle(atoi(attr[1].c_str()), atoi(attr[2].c_str()), atoi(attr[3].c_str()), atoi(attr[4].c_str()), attr[5]);
            Allshapes.shapes.push_back(new Rectangle(atoi(attr[1].c_str()), atoi(attr[2].c_str()), atoi(attr[3].c_str()), atoi(attr[4].c_str()), attr[5]));
        }
        //Allshapes.shapes.push_back(temp);
        Shapes::counter++;
        //delete temp;

    }
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
    //Shape* temp;
    if (parts[1] == "line")
    {
        //temp = new Line(atoi(parts[2].c_str()), atoi(parts[3].c_str()), atoi(parts[4].c_str()), atoi(parts[5].c_str()));
        Allshapes.shapes.push_back(new Line(atoi(parts[2].c_str()), atoi(parts[3].c_str()), atoi(parts[4].c_str()), atoi(parts[5].c_str())));
    }

    else if (parts[1] == "rectangle")
    {
        //temp = new Rectangle(atoi(parts[2].c_str()), atoi(parts[3].c_str()), atoi(parts[4].c_str()), atoi(parts[5].c_str()), parts[6]);
        Allshapes.shapes.push_back(new Rectangle(atoi(parts[2].c_str()), atoi(parts[3].c_str()), atoi(parts[4].c_str()), atoi(parts[5].c_str()), parts[6]));
    }
    else if (parts[1] == "circle")
    {
        //temp = new Rectangle(atoi(parts[2].c_str()), atoi(parts[3].c_str()), atoi(parts[4].c_str()), atoi(parts[5].c_str()), parts[6]);
        Allshapes.shapes.push_back(new Circle(atoi(parts[2].c_str()), atoi(parts[3].c_str()), atoi(parts[4].c_str()), parts[5]));
    }
    else
    {
        return;
    }
    Shapes::counter++;
    //Allshapes.shapes.push_back(temp);
    //delete temp;
    //Allshapes.shapes.push_back(temp);
    print();
    //  std::cout << "Successfully created " << temp->getShape() << " (" << Shapes::counter << ")" << "\n";

}
void FileManager::print()
{
    for (int i = 0; i <this->Allshapes.shapes.size(); i++)
    {
        std::string ans =Allshapes.shapes[i]->combine();
        std::cout << i + 1 << ". " << ans;
    }
}
bool FileManager::check_position(const int position, const int max_position) const
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
void FileManager::eraseIt(const int position)
{
    if(!check_position(position-1, Allshapes.shapes.size()))
        return;
    Shape* figure = Allshapes.shapes[position - 1];
    Allshapes.shapes.erase(Allshapes.shapes.begin() + position - 1);
    Shapes::counter--;
    std::cout << "Erased a " << figure->getShape() << " (" << position << ")\n";
    delete figure;
}
void FileManager::save()
{
    if (RealFileName == "")
    {
        std::cout << "There is no opened file!\n";
        return;
    }
    saveAs(RealFileName.c_str());
}
void FileManager::tri()
{
    Shapes shape;
    Shape* temp= new Line(1, 2, 3,4);
    Shape* temp2= new Line(1, 2, 3,5);
    Allshapes.shapes.push_back(temp);
    Allshapes.shapes.push_back(temp2);
    for (int i = 0; i < this->Allshapes.shapes.size(); i++)
    {
        std::string ans = Allshapes.shapes[i]->combine();
        std::cout << i + 1 << ". " << ans;
    }
    delete temp;
    delete temp2;
}

void FileManager::saveAs(const std::string &fileName)
{
    std::ofstream ofs(fileName, std::ios::out| std::ios::trunc);
    if(!ofs)
        std::cout<<"Failed to save to file"<<std::endl;

    for (int i = 0; i < this->Allshapes.shapes.size(); i++)
    {
        this->Allshapes.shapes[i]->writeToFile(ofs);
    }

    ofs.close();
    std::cout << "Successfully saved the changes to " << fileName << " \n";
}
int getNum(const std::string &str)
{
    std::string word;
    bool check = false;
    for (int x = 0; x<str.length(); x++)
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
void FileManager::translate(std::string* parts)
{

    int vertical = getNum(parts[2]);

    int horizontal= getNum(parts[1]);

    if (sizeof(parts) == 3)
    {
        for (int i = 0; i < this->Allshapes.shapes.size(); i++)
        {
            this->Allshapes.shapes[i]->translate(vertical, horizontal);
        }
        std::cout << "Translated all figures\n";
        return;
    }
    else
    {
        int index = atoi(parts[3].c_str());
        this->Allshapes.shapes[index-1]->translate(vertical, horizontal);
        std::cout << "Translated " << index << "\n";
    }
}
/*bool ItIsInsideRectangle(const Rectangle& rect, const Shape* shape)
{
	bool f1 =rect.CoordinatesOfBottomLeftPoint() <= shape->CoordinatesOfBottomLeftPoint();
    bool f2 = rect.CoordinatesOfBottomRightPoint() <= shape->CoordinatesOfBottomRightPoint();
    bool f3 = rect.CoordinatesOfTopLeftPoint() >= shape->CoodinatesOfTopLeftPoint();
    bool f4 rect.CoordinatesOfTopRightPoint() >= shape->CoordinatesOfTopRightPoint();
    if(f1 && f2 && f3 && f4) return true;
    return false;
}
void FileManager::within(std::string* parts)
{
	int* right;
	int counter = 0;
	if (parts[1]== "rectangle")
	{
		Rectangle* rect = new Rectangle(atoi(parts[2].c_str()), atoi(parts[3].c_str()), atoi(parts[4].c_str()), atoi(parts[5].c_str()));
		for (int i = 0; i < Allshapes.shapes.size(); i++)
		{

            if (ItIsInsideRectangle(rect, Allshapes.shapes[i]))
			{
				right[counter] = i;
				counter++
			}
		}
		delete rect;
	}

	if (counter == 0)
	{
		std::cout << "No shapes are located within ";
		for (int i = 1; i < parts.size(); i++)
		{
			std::cout << parts[i] << " ";
		}
		std::cout << "\n";
		return;
	}
	for (int i = 0; i < counter; i++)
	{
		std::cout << i + 1 << ". " << Allshapes.shapes[right[i]]->combine();
	}
	delete right;
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


