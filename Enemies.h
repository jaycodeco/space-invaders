#pragma once

#include "Game.h"
#include "Enemy.h"

#define maxEn 10
#define SpTMax 4

class Enemies
{

public:
	Enemies();
	~Enemies();

	void Draw(sf::RenderWindow* window);
	void Destroy(int i);
	void AddEnemy();
	void Update(float time);
	int Size() { return enemies.size(); }
	Enemy $(int i) { return enemies[i]; }


protected:
	std::vector<Enemy> enemies;
	int Sed;
	int points;
	float SpT;
	float timer;


};

