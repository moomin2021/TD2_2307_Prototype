#pragma once

class Key {
	// --�֎~-- //
public:
	// �R�s�[�R���X�g���N�^
	Key(const Key& instance) = delete;

	// ������Z�q
	Key& operator=(const Key& instance) = delete;

	// --�����o�֐�-- //
public:
	// �C���X�^���X�擾
	static Key* GetInstance();

	// �X�V����
	void Update();

	/// <summary>
	/// �L�[��������Ă��邩
	/// </summary>
	/// <param name="key"> �L�[�w�� </param>
	bool PushKey(int key) { return keys_[key]; }

	/// <summary>
	/// �L�[�������ꂽ�u�Ԃ�
	/// </summary>
	/// <param name="key"> �L�[�w�� </param>
	/// <returns></returns>
	bool TriggerKey(int key) { return (keys_[key] && !oldKeys_[key]); }

	/// <summary>
	/// �L�[�������ꂽ�u�Ԃ�
	/// </summary>
	/// <param name="key"> �L�[�w�� </param>
	/// <returns></returns>
	bool ReleaseKey(int key) { return (!keys_[key] && oldKeys_[key]); }

private:
	// �R���X�g���N�^
	Key();

	// �f�X�g���N�^
	~Key();

	// --�����o�ϐ�-- //
public:

private:
	// ���݂̓��͏��
	char keys_[256];

	// 1�t���[���O�̓��͏��
	char oldKeys_[256];

};