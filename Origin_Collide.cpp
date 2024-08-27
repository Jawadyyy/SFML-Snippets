#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;
using namespace sf;

int main()
{

    RenderWindow window(VideoMode(640, 480), "SFML", Style::Close | Style::Resize);
    window.setFramerateLimit(60);

    RectangleShape rect1(Vector2f(100.0f, 100.0f));
    rect1.setFillColor(Color::Red);
    rect1.setOrigin(50.0f, 50.0f);

    CircleShape circ(20.0f);
    circ.setFillColor(Color::Green);
    circ.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    circ.setOrigin(20.0f, 20.0f);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
            {
                window.close();
            }

        }

        //Rect1
        if (Keyboard::isKeyPressed(Keyboard::Key::A) && rect1.getPosition().x >0)
        {
            rect1.move(-3.5, 0.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::D) && (rect1.getPosition().x + rect1.getSize().x) < window.getSize().x)
        {
            rect1.move(3.5, 0.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::W) && rect1.getPosition().y > 0)
        {
            rect1.move(0.0f, -3.5f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::S) && (rect1.getPosition().y + rect1.getSize().y) < window.getSize().y)
        {
            rect1.move(0.0f, 3.5f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Space))
        {
            rect1.rotate(10.0f);
        }
        if (rect1.getGlobalBounds().intersects(circ.getGlobalBounds()))
        {
            circ.setFillColor(Color::Blue);
        }
        else
        {
            circ.setFillColor(Color::Green);
        }

        window.clear();
        window.draw(rect1);
        window.draw(circ);
        window.display();

    }

    return 0;
}
