#pragma once

#include "../../../Base/GameManagerContains/IGameManagerPtr.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"

#include <unordered_map>

//�V�[���C���^�[�t�F�C�X
class Transition
{
public:
	// �J�ڃ��[�h
	enum class Mode {
		In,
		Out
	};
	// �J�ڂ̃p�����[�^
	struct Parametor {
		// �ω��l
		float value;
		// �I���l
		float endValue;
	};
public:
	//�R���X�g���N�^
	Transition(const IGameManagerPtr& gameManager);
	//�f�t�H���g�R���X�g���N�^
	//Transition();
	// ���z�f�X�g���N�^     
	virtual ~Transition();
	// �J�n     
	virtual void start();
	// �X�V     
	virtual void update(float deltaTime);
	// �`��     
	virtual void draw()const;
	// ���[�h�̐؂肩��
	void changeMode(const Mode& mode);
	// �I���t���O
	virtual bool isEnd();

protected:
	// �J�n     
	virtual void onStart();
	//�X�V
	virtual void onUpdate(float deltaTime);
	//�`��
	virtual void onDraw() const;
protected:
	//�Q�[���}�l�[�W���[
	IGameManagerPtr p_GameManager;
	// �e�N�X�`���p�����[�^
	Texture2DParameter m_Param;
	// ���[�h�p�����[�^
	std::unordered_map<Mode, Parametor> mModeParametors;
	// ���݂̃��[�h
	Mode mMode;
	// �I���t���O
	bool m_IsEnd;
};
