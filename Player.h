#pragma once

#include "Collider.h"
#include "Ship.h"


class Player:protected Ship
{
public:
	Player();
	~Player();

	bool Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	sf::Vector2f GetPos() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	bool aLife() { return alife; }
	void lifeState(bool state) { alife = state; }

	int Score;


};

