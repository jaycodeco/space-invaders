#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <SFML/Graphics.hpp>

class Collider
{

public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollide(Collider other, float push);
	bool CollidesWith(Collider other);
	float CheckDistance(Collider other);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

protected:
	sf::RectangleShape& body;
};

