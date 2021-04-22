#include "Enemy.h"



Enemy::Enemy(float x, float y, const char* img)
{
	this->init(sf::Vector2f(30.0f, 40.0f), sf::Vector2f(x, y), "resources/IMGs/spaceShip7.png");

}

Enemy::~Enemy()
{
	
}

bool Enemy::Update(float deltaTime)
{
	if (body.getPosition().y > 600)
		return false;

	velocity.y += speed;

	body.move(velocity);
	velocity.x = 0.0f;
	velocity.y = 0.0f;

	return true;
}

void Enemy::Draw(sf::RenderWindow* window)
{
	window->draw(body);
}