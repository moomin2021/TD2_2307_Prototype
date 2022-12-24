#include "EnemyBullet.h"
#include "DxLib.h"

void EnemyBullet::Initialize(Vector2 pos, Vector2 speed)
{
	pos_ = pos;
	speed_ = speed;
	r_ = 12;
}

void EnemyBullet::Update()
{
	pos_ += speed_;
	if (pos_.x - r_ < 0) {
		isDead_ = true;
	}
	if (pos_.y - r_ < 0) {
		isDead_ = true;
	}
	if (pos_.x + r_ > 1000) {
		isDead_ = true;
	}
	if (pos_.y + r_ > 1000) {
		isDead_ = true;
	}
}

void EnemyBullet::Draw()
{
	DrawCircle(pos_.x, pos_.y, r_, GetColor(200, 200, 200), true);
}
