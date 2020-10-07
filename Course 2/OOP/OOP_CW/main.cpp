#include <SFML/Graphics.hpp>
#include <iostream>
#include "couse_lib.h"

int main()
{
    ProgramMenu();

    int custom_radius = 150; //Change it for A-Figure movement
    Circle ACircle(custom_radius); //A-Figure initialization
    Rectangle ARectangle_1(custom_radius);
    Rectangle ARectangle_2(custom_radius);
    Triangle ATriangle(custom_radius);

    Circle BCircle; //B-Figure initialization
    Rectangle BRectangle_1;
    Rectangle BRectangle_2;
    Triangle BTriangle;

    sf::ContextSettings settings;
    //settings.antialiasingLevel = 16; //AntiAliasing for figures
    sf::RenderWindow window(sf::VideoMode(800, 800), "OOP Course Work", sf::Style::Default, settings); //window initialization

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::sleep(sf::milliseconds(10));

        ACircle.FigureSettings(); //A-Figure draw
        ACircle.MoveFigure();
        window.draw(circle);

        ARectangle_1.FigureSettings();
        ARectangle_1.MoveFigure(50);
        window.draw(rectangle);

        ARectangle_2.FigureSettings();
        ARectangle_2.MoveFigure(-20);
        window.draw(rectangle);

        ATriangle.FigureSettings();
        ATriangle.MoveFigure();
        window.draw(triangle);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BCircle.FigureSettings(); //B-Figure draw
        BCircle.MoveFigure();
        window.draw(circle);

        BRectangle_1.FigureSettings();
        BRectangle_1.MoveFigure(50);
        window.draw(rectangle);

        BRectangle_2.FigureSettings();
        BRectangle_2.MoveFigure(-20);
        window.draw(rectangle);

        BTriangle.FigureSettings();
        BTriangle.MoveFigure();
        window.draw(triangle);

        window.display();
        window.clear();
    }
    return 0;
}
