#pragma once

#include "Collider.h"
#include "Enemies.h"
#include "Bullet.h"

class Bullets
{
public:
	Bullets();
	~Bullets();
	void shoot(Player shooter);
	void Update(Enemies& enemy);
	void Recharge();
	void Draw(sf::RenderWindow& window);


protected:
	std::vector<Bullet> charger;
	int Capacity[3];
	int HealthTake[3];
	int id, Shooted;
};

