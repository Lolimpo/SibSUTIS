#ifndef COURSE_LIB_H
#define COUSE_LIB_H

using namespace std;

sf::CircleShape circle(50);
sf::RectangleShape rectangle(sf::Vector2f(30, 50));
sf::CircleShape triangle (50, 3);

class Abstract
{
public:
    virtual void MoveFigure(int origin_x, int origin_y) = 0; //pure virtual function
    virtual void FigureSettings() = 0;
};

class MainClass: public Abstract
{
protected:
    int x; //x axis coordinate
    int y; //y axis coordinate
    int center_x; //window center x
    int center_y; //window center y
    int radius; //movement radius
    float angle; //angle
public:
    explicit MainClass() : center_x(400), center_y(400)//basic data constructor
    {
        angle = 0;
        radius = 275;
    }
    explicit MainClass(int custom_radius, int custom_angle = 90) //basic data constructor overloading
    {
        center_x = 400;
        center_y = 400;
        angle = custom_angle;
        radius = custom_radius;
    }
    friend void ProgramMenu(); //friendly function
};

class Circle: public MainClass
{
    using MainClass::MainClass;
public:
    void MoveFigure(int origin_x = 50, int origin_y = 50)
    {
        circle.setPosition(x, y);
        x = center_x + radius * cos(angle);
        y = center_y + radius * sin(angle);
        angle = angle - 0.01;
        circle.setOrigin(origin_x, origin_y);
        circle.rotate(2);
    }
    void FigureSettings()
    {
        circle.setFillColor(sf::Color::Yellow);
        circle.setOutlineThickness(1);
        circle.setOutlineColor(sf::Color::White);
    }
};

class Rectangle: public MainClass
{
    using MainClass::MainClass;
public:
    void MoveFigure(int origin_x = 50, int origin_y = -25)
    {
        rectangle.setPosition(x, y);
        x = center_x + radius * cos(angle);
        y = center_y + radius * sin(angle);
        angle = angle - 0.01;
        rectangle.setOrigin(origin_x, origin_y);
        rectangle.rotate(1);
    }
    void FigureSettings()
    {
        rectangle.setFillColor(sf::Color::Green);
        rectangle.setOutlineThickness(1);
        rectangle.setOutlineColor(sf::Color::White);
    }
};

class Triangle: public MainClass
{
    using MainClass::MainClass;
public:
    void MoveFigure(int origin_x = 50, int origin_y = 125)
    {
        triangle.setPosition(x, y);
        x = center_x + radius * cos(angle);
        y = center_y + radius * sin(angle);
        angle = angle - 0.01;
        triangle.setOrigin(origin_x, origin_y);
        triangle.rotate(2);
    }
    void FigureSettings()
    {
        triangle.setFillColor(sf::Color::Magenta);
        triangle.setOutlineThickness(1);
        triangle.setOutlineColor(sf::Color::White);
    }
};

void ProgramMenu()
{
    int button;
    cout << "Welcome!" << endl;
    cout << "1. Start Program" << endl;
    cout << "Any other to close" << endl;
    cin >> button;
    switch(button)
    {
    case 1:
        break;
    default:
        terminate();
        break;
    }
}
#endif // COURSE_LIB_H
