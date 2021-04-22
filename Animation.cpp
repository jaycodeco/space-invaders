#include "Animation.h"


Animation::Animation(std::string txtre, sf::Vector2u imageCount, sf::Vector2u spriteSize, float switchTime)
{
	texture.loadFromFile(txtre);
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	UvRect.width = texture.getSize().x / float(spriteSize.x);
	UvRect.height = texture.getSize().y / float(spriteSize.y);

}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	UvRect.top = currentImage.y * UvRect.height;
	UvRect.left = currentImage.x * abs(UvRect.width);
	UvRect.width = abs(UvRect.width);

}

