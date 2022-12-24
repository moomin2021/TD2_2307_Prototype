#pragma once
#include <DxLib.h>
#include "Vector2.h"
#include "EnemyBullet.h"
#include <list>
#include <memory>

class Boss
{
public:
	//初期化
	void Initialize();
	//毎フレーム処理
	void Update();
	//描画
	void Draw();

private:
	//座標
	Vector2 pos_;
	//大きさ(半径)
	float size_ = 50.0f;

	//弾の間隔
	uint32_t setCoolTime_ = 5 * 60;
	uint32_t coolTime_ = setCoolTime_;
	Vector2 speed_;

	std::list<std::unique_ptr<EnemyBullet>> bullet_;
};

