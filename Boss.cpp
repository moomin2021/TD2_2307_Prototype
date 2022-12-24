#include "Boss.h"

void Boss::Initialize()
{
	//位置の初期化
	pos_ = Vector2(500, 500);
	speed_ = Vector2(-2, 0);
}

void Boss::Update()
{
	if (coolTime_ >= 30) {
		if (pos_.x - size_ < 0) {
			speed_ = Vector2(2, 0);
		}
		if (pos_.x + size_ > 1000) {
			speed_ = Vector2(-2, 0);
		}
		pos_ += speed_;

	}
	if (--coolTime_ <= 0) {
		std::unique_ptr<EnemyBullet> newBullet = std::make_unique<EnemyBullet>();
		newBullet->Initialize(pos_, Vector2(3, 0));
		bullet_.push_back(std::move(newBullet));
		coolTime_ = setCoolTime_;
	}

	for (std::unique_ptr<EnemyBullet>& bullet : bullet_) {
		bullet->Update();
	}
}

void Boss::Draw()
{
	//ボス本体の描画
	DrawBox(pos_.x - size_, pos_.y - size_, pos_.x + size_, pos_.y + size_, GetColor(200, 0, 0),true);
	for (std::unique_ptr<EnemyBullet>& bullet : bullet_) {
		bullet->Draw();
	}
}
