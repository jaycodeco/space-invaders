#include "Bullets.h"

Bullets::Bullets()
{
    Capacity[0] = 200;
    HealthTake[0] = 10;
    Capacity[1] = 50;
    HealthTake[1] = 5;
    Capacity[2] = 10;
    HealthTake[2] = 10;
    Shooted = 0;
}

Bullets::~Bullets()
{
}

void Bullets::Recharge()
{
    for (int i = 0; i < 70; i++)
        charger.push_back((Bullet(i, "resources/IMGs/spaceShip1.png")));
}

void Bullets::shoot(Player shooter)
{
    charger[Shooted].Start(shooter.GetPos().x, shooter.GetPos().y - 30);
    Shooted++;
    
}

void Bullets::Update(Enemies& enemy)
{
    for (int i = 0; i < Shooted; i++)
        if (!charger[i].Update(enemy))
        {
            charger.erase(charger.begin() + i);
            Shooted--;
        }
            
            
    if (charger.size() < 10 )
        this->Recharge();
}


void Bullets::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < Shooted; i++)
        charger[i].Draw(window);
}
