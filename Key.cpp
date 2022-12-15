#include "Key.h"
#include "DxLib.h"

// �C���X�^���X�擾
Key* Key::GetInstance()
{
    // �֐���static�ϐ��Ƃ��Đ錾
    static Key instance;
    return &instance;
}

// �R���X�g���N�^
Key::Key() :
#pragma region ���������X�g
    keys_{},// -> ���݂̓��͏��
    oldKeys_{}// -> 1�t���[���O�̓��͏��
#pragma endregion
{}

// �f�X�g���N�^
Key::~Key() {}

// �X�V����
void Key::Update() {
    // 1�t���[���O�̏���ۑ�
    for (size_t i = 0; i < 256; i++) oldKeys_[i] = keys_[i];

    // �ŐV�̃L�[�{�[�h�����擾
    GetHitKeyStateAll(keys_);
}