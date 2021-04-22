#pragma once

#include "Collider.h"

class Animation
{
public:
	Animation(std::string txtre, sf::Vector2u imageCount, sf::Vector2u spriteSize, float switchTime);
	~Animation();

	void Update(int row, float deltaTime);

	sf::IntRect UvRect;
protected:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	sf::Texture texture;

	float totalTime;
	float switchTime;
};

