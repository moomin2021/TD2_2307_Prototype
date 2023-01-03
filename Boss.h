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

	void BulletShot(Vector2 way);

	int SetTime(int sec);

	void SetPlayerPos(Vector2 pos) {
		playerPos_ = pos;
	}

private:
	//座標
	Vector2 pos_;
	//大きさ(半径)
	float size_ = 50.0f;

	//弾の間隔
	uint32_t setCoolTime_ = 2 * 60;
	uint32_t coolTime_ = setCoolTime_;
	Vector2 speed_;
	//弾
	std::list<std::unique_ptr<EnemyBullet>> bullet_;

	//突進
	Vector2 dash_ = { 0,0 };

	//ジャンプ攻撃
	bool isJump_;
	int jumpTime_ = 2 * 60;
	int impactSize_;
	bool isImpact_;

	//ビーム攻撃
	int isBeam_ = 0;
	float beamLen_ = 0;
	Vector2 beamWay_;

	//プレイヤーの位置
	Vector2 playerPos_;
	

};

