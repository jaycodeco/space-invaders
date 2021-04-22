#pragma once
#include "Ship.h"


class Enemy :
    protected Ship
{
public:
    Enemy(float x, float y, const char* img);
	~Enemy();

	bool Update(float deltaTime);
	sf::Vector2f GetPos() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	bool aLife() { return alife; }
	void lifeState(bool state) { alife = state; }
	void Draw(sf::RenderWindow* window);
};

