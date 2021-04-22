#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Ship
{
public:
	Ship();
	~Ship();

	virtual bool Update(float deltaTime)=0;
	void init(sf::Vector2f size, sf::Vector2f pos, const char* image);
	sf::Vector2f GetPos() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	

protected:
	sf::RectangleShape body;
	sf::Texture texture;
	float speed;
	sf::Vector2f velocity;
	int hp;
	bool alife;

};

