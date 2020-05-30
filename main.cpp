#include "Shape.cpp"
#include "Line.cpp"
#include "Rectangle.cpp"
#include "Circle.cpp"
#include "FileManager.cpp"
using namespace std;
int main()
{
    //Line l(11, 7, 8, 5);
    //Line l(11, 7, 8, 5);
    // Line l(11, 7, 8, 5);
    /* Line l(7, 6, 8, 5);
     //l.print();
     Line m;
     // m.print();
     ofstream os;
     os.open("figures.svg",ios::in|ios::app);

     l.writeToFile(os);
     /*string word[4] = {};
     int counter = 0;
     string str = "red blue green black";
      removeSpace(str, word, counter);
     for(int i = 0; i < 4; i++) cout << word[i] << " " << i << endl;*/
    FileManager f;
    f.start();

    //f.tri();
    return 0;

}
