#include "Boss.h"

void Boss::Initialize()
{
	//位置の初期化
	pos_ = Vector2(500, 500);

}

void Boss::Update()
{
	
}

void Boss::Draw()
{
	//ボス本体の描画
	DrawBox(pos_.x - size_, pos_.y - size_, pos_.x + size_, pos_.y + size_, GetColor(200, 0, 0),true);
}
