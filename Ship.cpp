#include "Ship.h"



Ship::Ship()
{
}

Ship::~Ship()
{
}

void Ship::init(sf::Vector2f size, sf::Vector2f pos, const char* image)
{
	this->alife = true;
	speed = 3.1f;
	texture.loadFromFile(image);
	texture.setSmooth(1);
	body.setSize(size);
	body.setPosition(pos);
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(&texture);

}



