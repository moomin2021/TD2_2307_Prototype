#pragma once
#include "BaseScene.h"
#include "Key.h"
#include "Boss.h"

class GameScene : public BaseScene {
	// --�����o�ϐ�-- //
public:

private:
	// �L�[�{�[�h����
	Key* key_;

	// --�����o�֐�-- //
public:
	// �R���X�g���N�^
	GameScene();

	// �f�X�g���N�^
	~GameScene();

	// ����������
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

private:
	//�{�X
	Boss boss_;

};