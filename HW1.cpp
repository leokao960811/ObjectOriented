#include <iostream>
#include <vector>
using namespace std;

class Shape
{
    protected:
        int x, y;

    public:
        //Constructor
        Shape(int x, int y)
        {
            this->x = x; //this refers to the object itself, used due to same names
            this->y = y;
        }

        virtual void display() = 0;

        //Destructor
        virtual ~Shape(){}
};

class Circle: public Shape
{
    private:
        int radius; //hidden from others

    public:
    //Overloading constructor
        Circle(int x, int y, int r): Shape(x,y), radius(r){}
        void display() override
        {
            cout << "Circle at ("<< x << ","<< y <<")\n Radius: " << radius << endl;
        }
};

class Triangle: public Shape
{
    private:
        int angle; //hidden from others

    public:
    //Overloading constructor
        Triangle(int x, int y, int r): Shape(x,y), angle(r){}
        void display() override
        {
            cout << "Triangle at ("<< x << ","<< y <<")\n Angle: " << angle << endl;
        }
};

class Square: public Shape
{
    private:
        int area; //hidden from others

    public:
        //Overloading constructor
        Square(int x, int y, int r): Shape(x,y), area(r){}
        void display() override
        {
            cout << "Square at ("<< x << ","<< y <<")\n Area: " << area << endl;
        }
};

int main()
{

    vector <Shape*> shapes;

    
    shapes.push_back(new Square(5, 5, 25));
    shapes.push_back(new Triangle(2, 3, 60));
    shapes.push_back(new Circle(9, 8, 10));
    shapes.push_back(new Square(4, 4, 16));
    shapes.push_back(new Circle(1, 6, 7));
    shapes.push_back(new Triangle(9, 10, 90));

    cout << "Number of shapes: " << shapes.size() << endl;
    cout << endl;

    for(Shape* s: shapes)
    {
        s->display();
        cout << endl;
    }

    for(Shape* s: shapes)
    {
        delete s;
    }

    return 0;

}