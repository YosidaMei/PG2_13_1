#pragma once
#include "Function.h"
#include <Novice.h>

class Bullet
{
public:
	Vector2 pos_;
	int r_;
	int speed_;
	int isShot_;
public:
	Bullet();
	void Update();
	void Draw();
};

