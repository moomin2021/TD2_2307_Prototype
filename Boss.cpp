#include "Boss.h"

void Boss::Initialize()
{
	//�ʒu�̏�����
	pos_ = Vector2(500, 500);

}

void Boss::Update()
{
	
}

void Boss::Draw()
{
	//�{�X�{�̂̕`��
	DrawBox(pos_.x - size_, pos_.y - size_, pos_.x + size_, pos_.y + size_, GetColor(200, 0, 0),true);
}
