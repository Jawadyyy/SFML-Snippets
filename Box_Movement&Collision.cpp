#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void update(RectangleShape &square, RenderWindow& window);
void draw(RenderWindow &window, RectangleShape &square);

int main()
{
    RenderWindow window(VideoMode(640, 480), "SFML", Style::Close | Style::Resize);
    window.setFramerateLimit(60);

    RectangleShape box(Vector2f(75.0f,75.0f));
    box.setFillColor(Color::White);
    box.setPosition(window.getSize().x / 2, window.getSize().y / 2);

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

        update(box, window);
        draw(window,box);

        //window.clear();
        //window.display();
    }

    return 0;
}

void update(RectangleShape &square, RenderWindow& window)
{

    if (Keyboard::isKeyPressed(Keyboard::Key::Left) && square.getPosition().x>0)
    {
        square.move(-2.5f,0.0f);
    }
    
    if (Keyboard::isKeyPressed(Keyboard::Key::Right) && (square.getPosition().x + square.getSize().x) < window.getSize().x)

    {
        square.move(2.5f,0.0f);
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::Up) && square.getPosition().y > 0)
    {
        square.move(0.0f,-2.5f);
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::Down) && (square.getPosition().y + square.getSize().y) < window.getSize().y)

    {
        square.move(0.0f,2.5f);
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::Space))
    {
        square.rotate(2.5f);
    }

    if (Mouse::isButtonPressed(Mouse::Button::Left))
    {
        square.setFillColor(Color::Blue);
    }
    else
    {
        square.setFillColor(Color::White);
    }


}

void draw(RenderWindow &window,RectangleShape &square)
{
    window.clear();

    window.draw(square);

    window.display(); 
}