#pragma once
#include <DxLib.h>
#include "Vector2.h"
#include "EnemyBullet.h"
#include <list>
#include <memory>

class Boss
{
public:
	//������
	void Initialize();
	//���t���[������
	void Update();
	//�`��
	void Draw();

private:
	//���W
	Vector2 pos_;
	//�傫��(���a)
	float size_ = 50.0f;

	//�e�̊Ԋu
	uint32_t setCoolTime_ = 5 * 60;
	uint32_t coolTime_ = setCoolTime_;
	Vector2 speed_;

	std::list<std::unique_ptr<EnemyBullet>> bullet_;
};

