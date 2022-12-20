#pragma once
#include <DxLib.h>
#include "Vector2.h"

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

};

