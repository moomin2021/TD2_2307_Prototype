#include "GameScene.h"

GameScene::GameScene()
{
	//�{�X�̏�����
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
	//�{�X�̓���
	boss_.Update();
}

void GameScene::Draw()
{
	//�{�X�̕`��
	boss_.Draw();
}
