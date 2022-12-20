#pragma once
#include <DxLib.h>
#include "Vector2.h"

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

};

