#include "GameScene.h"

GameScene::GameScene()
{
	//ボスの初期化
	boss_.Initialize();
}

GameScene::~GameScene()
{

}

void GameScene::Initialize()
{

}

void GameScene::Update()
{
	//ボスの動き
	boss_.Update();
}

void GameScene::Draw()
{
	//ボスの描画
	boss_.Draw();
}
