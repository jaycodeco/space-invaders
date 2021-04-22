#include "Player.h"



Player::Player()
{
	this->init(sf::Vector2f(40.0f, 60.0f), sf::Vector2f(135.0f, 540.0f), "resources/IMGs/spaceShip7.png");
	this->Score = 0;
	speed = 75.0f;
}

Player::~Player()
{
}

bool Player::Update(float deltaTime)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		velocity.y -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		velocity.y += speed;


	body.move(velocity * deltaTime);
	velocity.x = 0.0f;
	velocity.y = 0.0f;

	return true;
}

void Player::Draw(sf::RenderWindow* window)
{
	window->draw(body);
}

