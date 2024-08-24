#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));
    int hp = 7;
    int score = 0;
    string name;

    //Audio
    SoundBuffer buffer,buff;
    buffer.loadFromFile("pop.wav");
    buff.loadFromFile("start.wav");
    Sound col,str;
    col.setBuffer(buffer);
    str.setBuffer(buff);

    RenderWindow window(VideoMode(640, 480), "Practice", Style::Close | Style::Resize);
    window.setFramerateLimit(60);

    //HpBar

    RectangleShape hpbar;
    hpbar.setFillColor(Color::White);
    hpbar.setSize(Vector2f((float)hp * 20.0f,20.0f));
    hpbar.setPosition(window.getSize().x/2-100,10.0f);
   
    //Loading all the textures and making them into Sprites

    Texture pactex,blobtex;
    pactex.loadFromFile("paced.png");
    blobtex.loadFromFile("enemy.png");
    Sprite pacman,blob;
    pacman.setTexture(pactex);
    blob.setTexture(blobtex);

    //Modifying the Sprites

    pacman.setScale(Vector2f(0.2f,0.2f));

    int timer = 40;
    blob.setScale(Vector2f(0.15f,0.15f));
    vector<Sprite> blobs;
    blobs.push_back(Sprite(blob));

    str.play();

    //cout << "Enter your name player: " << endl;
    //cin >> name;

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

            if (hp <= 0)
            {
                window.close();
            }
        }

        //Pac

        pacman.setPosition(pacman.getPosition().x, Mouse::getPosition(window).y);

        if (pacman.getPosition().y > (window.getSize().y - pacman.getGlobalBounds().height))
        {
            pacman.setPosition(pacman.getPosition().x, window.getSize().y - pacman.getGlobalBounds().height);
        }
        
        if (pacman.getPosition().y < 0)
        {
            pacman.setPosition(pacman.getPosition().x, 0);
        }

        //Blob

        for (int i = 0; i < blobs.size(); i++)
        {
            blobs[i].move(-5.0f, 0.0f);

            if (blobs[i].getPosition().x < (0 - blob.getGlobalBounds().width))
            {
                blobs.erase(blobs.begin() + i);
                hp--;
            }

        }

        if (timer < 40)
        {
            timer++;
        }
        if (timer >= 40)
        {
            timer = 0;
            blobs.push_back(Sprite(blob));
            blob.setPosition(window.getSize().x,rand()%int(window.getSize().y - blob.getGlobalBounds().height));
        }

        //Collision

        for (int i = 0; i < blobs.size(); i++)
        {
            if (pacman.getGlobalBounds().intersects(blobs[i].getGlobalBounds()))
            {
                blobs.erase(blobs.begin() + i);
                col.play();
                score++;
                cout << "Score: " << score << endl;
            }
            
        }

        //Update

        hpbar.setSize(Vector2f((float)hp * 20.0f, 20.0f));

        //Windows

        window.clear();
        window.draw(hpbar);
        window.draw(pacman);
        for (int i = 0; i < blobs.size() ; i++)
        {
            window.draw(blobs[i]);
        }
        window.display();


    }

    return 0;
}

