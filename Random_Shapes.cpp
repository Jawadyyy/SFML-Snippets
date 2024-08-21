#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Player
{

};

int main()
{
    RenderWindow window(VideoMode(730, 480), "SFML", Style::Close | Style::Resize);
    window.setFramerateLimit(60);
    RectangleShape rect(Vector2f(100.0f, 100.0f));
    CircleShape circ(30.0f);
    CircleShape tri(40.0f);
    Vertex line[] = { Vertex(Vector2f(100.0f,400.0f),Vector2f(50.0f,100.0f))};
    circ.setOutlineThickness(5.5f);
    circ.setOutlineColor(Color::Yellow);
    tri.setPointCount(3);
    rect.setFillColor(Color::Red);
    circ.setFillColor(Color::Cyan);
    tri.setFillColor(Color::Green);

    rect.setPosition(40.0f, 40.0f);
    circ.setPosition(200.0f, 250.0f);
    tri.setPosition(500.0f, 300.0f);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(rect);
        window.draw(circ);
        window.draw(line, 2, Lines);
        window.draw(tri);
        rect.move(1.5f,0.0f);
        rect.rotate(1.5f);
        tri.rotate(1.0f);
        circ.rotate(-1.5f);
        window.display();
    }

    return 0;
}