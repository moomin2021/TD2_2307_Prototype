#pragma once
#include <DxLib.h>
#include "Vector2.h"

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

};

