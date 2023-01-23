#pragma once
#include "Function.h"
#include <Novice.h>
#include "Player.h"
#include "Bullet.h"
#define USE_MATH_DEFINE
#include "cmath"

class Enemy
{
public:
	Vector2 pos_;
	int r_;
	int speed;
	static int isAlive;
public:
	void Draw();
	void Update(Bullet& bullet);
	Enemy(int posX, int posY);
};

