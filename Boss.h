#pragma once
#include <DxLib.h>
#include "Vector2.h"
#include "EnemyBullet.h"
#include <list>
#include <memory>

class Boss
{
public:
	//‰Šú‰»
	void Initialize();
	//–ˆƒtƒŒ[ƒ€ˆ—
	void Update();
	//•`‰æ
	void Draw();

private:
	//À•W
	Vector2 pos_;
	//‘å‚«‚³(”¼Œa)
	float size_ = 50.0f;

	//’e‚ÌŠÔŠu
	uint32_t setCoolTime_ = 5 * 60;
	uint32_t coolTime_ = setCoolTime_;
	Vector2 speed_;

	std::list<std::unique_ptr<EnemyBullet>> bullet_;
};

