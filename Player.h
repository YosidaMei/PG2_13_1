#pragma once
#include "Function.h"
#include <Novice.h>
#include "Bullet.h"

class Player
{
public:
	Vector2 pos_;
	int r_;
	int speed_;

public:
	Bullet bullet_;
	Player();
	void Draw();
	void Update(char* keys, char* preKeys);

};

