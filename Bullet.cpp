#include "Bullet.h"


Bullet::Bullet(int id, const char* img)
{
    body.setSize(sf::Vector2f(5.0f, 5.0f));
    body.setOrigin(body.getSize() / 2.0f);
    
    txtr.loadFromFile("resources/IMGs/spaceShip1.png");
    body.setTexture(&txtr);

    Id = id;
}

Bullet::~Bullet()
{
}


bool Bullet::Update(Enemies& enemy)
{
    body.move(0, -5.1f);

    for (int j = 0; j < enemy.Size(); j++)
    {
        if (enemy.$(j).GetCollider().CollidesWith(body))
        {
            enemy.Destroy(j);
            return false;
        }
    }


    if (body.getPosition().y < 0)
    {
        return false;
    }

    
    return true;
}


void Bullet::Draw(sf::RenderWindow& window)
{
   
        window.draw(body);
}
