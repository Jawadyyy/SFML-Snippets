#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>


using namespace std;
using namespace sf;

int main()
{
    float posx = 5;
    float posy = 5;
    int score1 = 0;
    int score2 = 0;

    RenderWindow window(VideoMode(800, 600), "Pong", Style::Close | Style::Resize);
    window.setFramerateLimit(60);

    Texture ground;
    ground.loadFromFile("grnd.jpg");
    Sprite s(ground);

    Font fot1,fot2;
    Text hi;

    fot1.loadFromFile("fut.ttf");
    hi.setFont(fot1);
    hi.setCharacterSize(15);
    hi.setFillColor(Color::White);
    hi.setStyle(Text::Regular);
    hi.setString("Score: 0-0");
    hi.setPosition(window.getSize().x/2-75, 10.0f);

    RectangleShape rect1(Vector2f(20.0f, 150.0f));
    rect1.setPosition(10.0f, window.getSize().y / 2-75);
    RectangleShape rect2(Vector2f(20.0f, 150.0f));
    rect2.setPosition(770.0f, window.getSize().y / 2-75);

    CircleShape circ(10.0f);
    circ.setFillColor(Color::White);
    circ.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    circ.setOrigin(10.0f, 10.0f);



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
        //Rect 1 Movement and Restrictions
        if (Keyboard::isKeyPressed(Keyboard::Key::W) && rect1.getPosition().y > 0)
        {
            rect1.move(0.0f, -5.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::S) && (rect1.getPosition().y + rect1.getSize().y) < window.getSize().y)
        {
            rect1.move(0.0f, 5.0f);
        }
        //Rect 2 Movement and Restrictions
        if (Keyboard::isKeyPressed(Keyboard::Key::Up) && rect2.getPosition().y > 0)
        {
            rect2.move(0.0f, -5.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Down) && (rect2.getPosition().y + rect2.getSize().y) < window.getSize().y)
        {
            rect2.move(0.0f, 5.0f);
        }
        //Ball Movement
        if (circ.getPosition().x > 800 - 10)
        {
            posx = -posx;
            score1++;
            hi.setString("Score: " + to_string(score1) + "-" + to_string(score2));
            this_thread::sleep_for(chrono::milliseconds(200));
            circ.setPosition(window.getSize().x / 2, window.getSize().y / 2);
        }
        if (circ.getPosition().x < 0 + 10)
        {
            posx = -posx;
            score2++;
            hi.setString("Score: " + to_string(score1) + "-" + to_string(score2));
            this_thread::sleep_for(chrono::milliseconds(200));
            circ.setPosition(window.getSize().x / 2, window.getSize().y / 2);
        }
        if (circ.getPosition().y > 600 - 10 || circ.getPosition().y < 0 + 10)
        {
            posy = -posy;
           
        }
        //Collision
        if (circ.getGlobalBounds().intersects(rect1.getGlobalBounds()))
        {
            posx = -posx;
        }
        else if(circ.getGlobalBounds().intersects(rect2.getGlobalBounds()))
        {
            posx = -posx;
        }
       
        //Window Functions
        window.clear();
        window.draw(s);
        window.draw(rect1);
        window.draw(rect2);
        window.draw(circ);
        window.draw(hi);
        circ.move(posx*2, posy);
        window.display();

    }

    return 0;
}
