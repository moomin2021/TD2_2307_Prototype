#include "SceneManager.h"
#include "DxLib.h"
#include "GameScene.h"

// �C���X�^���X�擾
SceneManager* SceneManager::GetInstance() {
    // �֐���static�ϐ��Ƃ��Đ錾
    static SceneManager instance;
    return &instance;
}

SceneManager::SceneManager() :
#pragma region ���������X�g
    myScene_(nullptr),// -> ���݂̃V�[��
    sceneNo_(0)// -> ���݂̃V�[���ԍ�
#pragma endregion
{
    // �L�[�{�[�h���̓N���X�̃C���X�^���X�擾
    key_ = Key::GetInstance();
}

// �f�X�g���N�^
SceneManager::~SceneManager() {
    // ���݂̃V�[������ł͂Ȃ�������
    if (myScene_ != nullptr) {
        // ���݂̃V�[�������������
        delete myScene_;
    }
}

// �V�[����ύX
void SceneManager::ChangeScene(int sceneNo) {
    // ���݂̃V�[������ł͂Ȃ�������
    if (myScene_ != nullptr) {
        // ���݂̃V�[�������������
        delete myScene_;
    }

    // �w�肳�ꂽ�V�[���̃C���X�^���X�����Ə�����
    switch (sceneNo)
    {
    case SCENE::GAME:
        myScene_ = new GameScene();// -> �C���X�^���X����
        myScene_->Initialize();// -> ���݂̃V�[���̏���������
        sceneNo_ = SCENE::GAME;// -> ���݂̃V�[���ԍ���ύX
        break;
    }
}

// �X�V����
void SceneManager::Update() {
    // [SPACE]�L�[�ŃV�[����ύX
    if (key_->TriggerKey(KEY_INPUT_SPACE)) {
        // ���݂̃V�[���ԍ���i�߂�
        sceneNo_++;

        // ���݂̃V�[���ԍ����ő�l�ȏ�Ȃ�
        if (sceneNo_ > SCENE::GAME) {
            // ���݂̃V�[���ԍ���0�ɂ���
            sceneNo_ = 0;
        }

        // �V�[����ύX����
        ChangeScene(sceneNo_);
    }

    // ���݂̃V�[���̍X�V����
    myScene_->Update();
}

// �`�揈��
void SceneManager::Draw() {
    // ���݂̃V�[���̕`�揈��
    myScene_->Draw();
}