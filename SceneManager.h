#pragma once
#include "BaseScene.h"
#include "Key.h"

// �V�[���񋓌^
enum SCENE {
	GAME
};

class SceneManager {
	// --�֎~-- //
public:
	// �R�s�[�R���X�g���N�^
	SceneManager(const SceneManager& instance) = delete;

	// ������Z�q
	SceneManager& operator=(const SceneManager& instance) = delete;

	// --�����o�֐�-- //
public:
	// �C���X�^���X�擾
	static SceneManager* GetInstance();

	// �V�[����ύX
	void ChangeScene(int sceneNo);

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

private:
	// �R���X�g���N�^
	SceneManager();

	// �f�X�g���N�^
	~SceneManager();

	// --�����o�ϐ�-- //
public:

private:
	// �L�[�{�[�h����
	Key* key_;

	// ���݂̃V�[��
	BaseScene* myScene_;

	// ���݂̃V�[���ԍ�
	int sceneNo_;
};