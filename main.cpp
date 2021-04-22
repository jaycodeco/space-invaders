#include "Game.h"
#include "Bullets.h"

using namespace std;
using namespace sf;


#define VIEW_WIDTH  450
#define VIEW_HEIGTH  600


void ResizeView(const RenderWindow& win, View& view)
{
    float aspectRatio = float(win.getSize().x) / float(win.getSize().y);
    float aspectRatio1 = float(win.getSize().y) / float(win.getSize().x);
    view.setSize(VIEW_HEIGTH * aspectRatio, VIEW_HEIGTH);
}


int main()
{
    //Drawing the window
    RenderWindow win(VideoMode(VIEW_WIDTH, VIEW_HEIGTH), "space invaders");
    win.setFramerateLimit(60);
    View view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_WIDTH, VIEW_HEIGTH));
    //******************
    int points = 0;
    //definining some variables
    float deltaTime = 0.0f;
    Clock clock;

    Texture BarTexture;
    BarTexture.loadFromFile("resources/IMGs/BarTexture.png");
    RectangleShape StatusBar;
    StatusBar.setTexture(&BarTexture);
    StatusBar.setSize(Vector2f(100, 600));
    StatusBar.setPosition(0, 0);


    //declaring animations
    Player player;

    Enemies Monsters;
    //
    Bullets bullet;
    bullet.Recharge();





    //	********************

    while (win.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        if (deltaTime > 1.0f / 20.0f)
        {
            deltaTime = 1.0f / 20.0f;
        }
        Event e;
        //Managing events
        while (win.pollEvent(e))
        {
            switch (e.type)
            {
            case Event::Closed:
                win.close();
                break;
            case Event::KeyPressed:
                switch (e.key.code)
                {
                case Keyboard::N:
                    win.close();
                    break;
                case Keyboard::P:
                    bullet.shoot(player);
                    break;
                }
                break;
            case Event::Resized:
                ResizeView(win, view);
                break;
            }
        }
        //********************


        //Updating Animations

        player.Update(deltaTime);
        Monsters.Update(deltaTime);
        bullet.Update(Monsters);


        if (!player.aLife())
        {
            win.close();
        }
        //drawing on the window
        win.clear(Color(20, 20, 50, 255));


        player.Draw(&win);
        Monsters.Draw(&win);
        bullet.Draw(win);
        win.draw(StatusBar);

        win.display();

        //*************
    }
    return EXIT_SUCCESS;
}
