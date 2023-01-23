#include "Player.h"

Player::Player() {
	pos_.x = 200;
	pos_.y = 600;
	r_ = 50;
	speed_ = 5;
}
void Player::Draw() {
	bullet_.Draw();
	Novice::DrawEllipse(pos_.x, pos_.y, r_, r_, 0.0f, WHITE, kFillModeSolid);
}

void Player::Update(char* keys, char* preKeys) {

	bullet_.Update();
	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}
	if (bullet_.isShot_ == 0) {
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			bullet_.pos_.x = pos_.x;
			bullet_.pos_.y = pos_.y;
			bullet_.isShot_ = 1;
		}
	}
}