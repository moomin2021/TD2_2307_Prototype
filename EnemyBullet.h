#pragma once
#include "Vector2.h"

class EnemyBullet
{
public:
	void Initialize(Vector2 pos,Vector2 speed);
	void Update();

	void Draw();
	bool IsDead() {
		return isDead_;
	};

private:
	Vector2 pos_;
	Vector2 speed_;
	float r_;
	bool isDead_;
};

