#include "Enemies.h"


Enemies::Enemies()
{
}

Enemies::~Enemies()
{
}




void Enemies::Destroy(int i)
{
    enemies.erase(enemies.begin() + i);
}

void Enemies::AddEnemy()
{
    enemies.push_back(Enemy(
        static_cast<float>((rand() % 345) +120),
        static_cast<float>(rand() % 10 ),
        "resources/IMGs/spaceShip7.png")
    );
}

void Enemies::Update(float time)
{
    timer += time;
    if (timer >= 0.1f)
    {
        timer -= 0.1f;
        if (enemies.size() < maxEn)
        {
            if (SpT >= SpTMax)
            {
                this->AddEnemy();
                SpT = 0.0f;
            }
            else
            {
                SpT += 0.1f;
            }
            SpT += 0.1f;
        }
    }


    for (int i = 0; i < enemies.size(); i++)
    {
        
        if(!enemies[i].Update(time))
            this->Destroy(i);

    }
}


void Enemies::Draw(sf::RenderWindow* window)
{
    for (int i = 0; i < enemies.size(); i++)
        enemies[i].Draw(window);

}