#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(640, 480), "Practice", Style::Close | Style::Resize);
    window.setFramerateLimit(60);

    int direction=0;
    bool fire = false;

    CircleShape enemy(50.0f);
    enemy.setFillColor(Color::White);
    enemy.setOutlineThickness(5);
    enemy.setOutlineColor(Color::Green);
    enemy.setPosition(Vector2f(0.0f, 10.0f));

    CircleShape ship(25.0f);
    ship.setFillColor(Color::Red);
    ship.setOutlineThickness(2);
    ship.setOutlineColor(Color::Cyan);
    ship.setPosition(1.25f, window.getSize().y - ship.getRadius() * 3);
   

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

        //enemy

        if (enemy.getPosition().x <= 0)
        {
            direction = 0;
        }
        else if ((enemy.getPosition().x + enemy.getRadius()*2) >= window.getSize().x)
        {
            direction = 1;
        }

        if (direction == 0)
        {
            enemy.move(5.0f, 0.0f);
        }
        else if (direction == 1)
        {
            enemy.move(-5.0f, 0.0f);
        }

        //ship
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            fire = true;
        }

        if (!fire)
        {
            Vector2i mousePos = Mouse::getPosition(window);
            if (mousePos.x >= 0 && mousePos.x < window.getSize().x-50 && mousePos.y >= 0 && mousePos.y < window.getSize().y)
            {
                ship.setPosition(static_cast<float>(mousePos.x), ship.getPosition().y);
            }
        }
        else
        {
            ship.move(0.0f, -5.0f);
        }

        //Collision

        if (ship.getPosition().y <= 0 || ship.getGlobalBounds().intersects(enemy.getGlobalBounds()))
        {
            fire = false;
            ship.setPosition(ship.getPosition().x, window.getSize().y - ship.getRadius() * 3);
        }

        //windows

        window.clear();
        window.draw(enemy);
        window.draw(ship);
        window.display();


    }

    return 0;
}

