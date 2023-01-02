#include "Boss.h"
#include "stdio.h"
#include "time.h"

void Boss::Initialize()
{
	//位置の初期化
	pos_ = Vector2(500, 500);
	speed_ = Vector2(-2, 0);
}

void Boss::Update()
{
	srand(time(NULL));
	int pattern = rand() % 30;
	//int pattern = 4;

	if (--coolTime_ <= 0) {
		if (pattern == 0) {
			dash_ = { 20,0 };
			coolTime_ = SetTime(1);
		}
		else if (pattern == 1) {
			dash_ = { 0,20 };
			coolTime_ = SetTime(1);
		}
		else if (pattern == 2) {
			dash_ = { -20,0 };
			coolTime_ = SetTime(1);
		}
		else if (pattern == 3) {
			dash_ = { 0,-20 };
			coolTime_ = SetTime(1);
		}
		else if (pattern >= 4 && pattern <= 10) {
			isJump_ = true;
		}
		else {

			BulletShot(Vector2(0, 3));
			BulletShot(Vector2(3, 0));
			BulletShot(Vector2(0, -3));
			BulletShot(Vector2(-3, 0));
			BulletShot(Vector2(2.4f, 2.4f));
			BulletShot(Vector2(-2.4f, -2.4f));
			BulletShot(Vector2(2.4f, -2.4f));
			BulletShot(Vector2(-2.4f, 2.4f));
			coolTime_ = SetTime(2);
		}

	}

	pos_ += dash_;
	if (dash_.x < 0) {
		dash_.x++;
		if (pos_.x < 0 + size_) {
			pos_.x = 0 + size_;
		}
	}
	else if (dash_.x > 0) {
		dash_.x--;
		if (pos_.x > 1000 - size_) {
			pos_.x = 1000 - size_;
		}
	}
	if (dash_.y < 0) {
		dash_.y++;
		if (pos_.y < 0 + size_) {
			pos_.y = 0 + size_;
		}
	}
	else if (dash_.y > 0) {
		dash_.y--;
		if (pos_.y > 1000 - size_) {
			pos_.y = 1000 - size_;
		}
	}

	if (isJump_ == true) {
		if (size_ == 10) {
			jumpTime_--;
			if (jumpTime_ == 0) {
				isJump_ = false;
				jumpTime_ = SetTime(3);
				coolTime_ = SetTime(5);
			}
		}
		else {
			size_--;
		}
		Vector2 len = playerPos_ - pos_;
		len.normalize();
		pos_ += len * 3;
	}
	else {
		if (size_ < 50) {
			size_++;
		}
		if (size_ == 49) {
			isImpact_ = true;
		}
	}

	if (isImpact_ == true) {
		impactSize_ += 10;
		if (impactSize_ >= 100) {
			isImpact_ = false;
		}
	}
	else {
		if (impactSize_ > 0) {
			impactSize_ -= 10;
		}
	}

	for (std::unique_ptr<EnemyBullet>& bullet : bullet_) {
		bullet->Update();
	}
}

void Boss::Draw()
{
	//ボス本体の描画
	if (size_ == 50.0f) {
		DrawBox(pos_.x - size_, pos_.y - size_, pos_.x + size_, pos_.y + size_, GetColor(200, 0, 0), true);
	}
	else {
		DrawCircle(pos_.x, pos_.y, size_, GetColor(50, 50, 50), true);
	}
	DrawCircle(pos_.x, pos_.y, impactSize_, GetColor(250, 250, 0), true);

	for (std::unique_ptr<EnemyBullet>& bullet : bullet_) {
		bullet->Draw();
	}
}

void Boss::BulletShot(Vector2 way)
{
	std::unique_ptr<EnemyBullet> newBullet = std::make_unique<EnemyBullet>();
	newBullet->Initialize(pos_, Vector2(way));
	bullet_.push_back(std::move(newBullet));
}

int Boss::SetTime(int sec)
{
	return sec * 60;
}
