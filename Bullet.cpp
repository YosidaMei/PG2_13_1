#include "Bullet.h"

Bullet::Bullet() {
	pos_.x = -100;
	pos_.y = -100;
	r_ = 30;
	speed_ = 10;
	isShot_ = 0;
}
void Bullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse(pos_.x, pos_.y, r_, r_, 0.0f, BLUE, kFillModeSolid);
	}
}
void Bullet::Update() {
	if (isShot_) {
		pos_.y -= speed_;
	}
	if (pos_.y <= -100) {
		isShot_ = 0;
	}
}
