#pragma once

#include "Collider.h"
#include "Enemies.h"

class Bullet
{
public:
	Bullet(int id, const char* img);
	~Bullet();
	bool Update(Enemies& enemy);
	void Draw(sf::RenderWindow& window);
	void Start(float x, float y) { body.setPosition(x,y); }


private:
	sf::RectangleShape body;
	sf::Texture txtr;
	int damage;
	int Id;
};

