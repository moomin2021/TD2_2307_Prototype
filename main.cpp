#include "DxLib.h"
#include "Key.h"
#include "SceneManager.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char Title[] = "LE2A_14_�^����_�t�~��: �^�C�g��";

// �E�B���h�E����
const int WIN_WIDTH = 1000;

// �E�B���h�E�c��
const int WIN_HEIGHT = 1000;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(Title);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾

	// �L�[�{�[�h���̓N���X�̃C���X�^���X�擾
	Key* key = Key::GetInstance();

	// �V�[���Ǘ��N���X�̃C���X�^���X�擾
	SceneManager* sceneM = SceneManager::GetInstance();
	sceneM->ChangeScene(SCENE::GAME);// -> �ŏ��̃V�[��

	// �Q�[�����[�v
	while (true) {
		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

#pragma region �X�V����
		// �L�[�{�[�h���͍X�V
		key->Update();

		// �V�[���Ǘ��N���X�X�V
		sceneM->Update();
#pragma endregion

#pragma region �`�揈��
		sceneM->Draw();
#pragma endregion

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
