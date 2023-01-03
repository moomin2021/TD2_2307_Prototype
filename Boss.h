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

	void BulletShot(Vector2 way);

	int SetTime(int sec);

	void SetPlayerPos(Vector2 pos) {
		playerPos_ = pos;
	}

private:
	//���W
	Vector2 pos_;
	//�傫��(���a)
	float size_ = 50.0f;

	//�e�̊Ԋu
	uint32_t setCoolTime_ = 2 * 60;
	uint32_t coolTime_ = setCoolTime_;
	Vector2 speed_;
	//�e
	std::list<std::unique_ptr<EnemyBullet>> bullet_;

	//�ːi
	Vector2 dash_ = { 0,0 };

	//�W�����v�U��
	bool isJump_;
	int jumpTime_ = 2 * 60;
	int impactSize_;
	bool isImpact_;

	//�r�[���U��
	int isBeam_ = 0;
	float beamLen_ = 0;
	Vector2 beamWay_;

	//�v���C���[�̈ʒu
	Vector2 playerPos_;
	

};

