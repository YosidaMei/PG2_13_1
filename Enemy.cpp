#include "Enemy.h"

Enemy::Enemy(int posX,int posY) {
	pos_.x = posX;
	pos_.y = posY;
	speed = 5;
	r_ = 30;
	isAlive = 1;
}
void Enemy::Update(Bullet& bullet) {
	int e2bR = bullet.r_ + r_;
	Vector2 e2b = { bullet.pos_.x - pos_.x ,bullet.pos_.y - pos_.y };
	
	if (isAlive) {
		pos_.x += speed;
		if (pos_.x >= 1280 - r_ || pos_.x <= 0 + r_) {
			speed *= -1;
		}
	}

	//“–‚½‚è”»’è
	if (pow(e2b.x, 2) + pow(e2b.y, 2) <= pow(e2bR, 2)) {
		isAlive = 0;
	}
	
}
void Enemy::Draw() {
	if (isAlive) {
		Novice::DrawEllipse(pos_.x, pos_.y, r_, r_, 0.0f, RED, kFillModeSolid);
	}
}
