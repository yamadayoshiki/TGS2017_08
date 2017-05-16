#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "../IGameManager.h"

class GameManager :public IGameManager
{
public:
	//�R���X�g���N�^
	GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState);
	//�X�V����
	void Update();
	//�R�s�[�֎~
	GameManager& operator = (const GameManager& other) = delete;
	GameManager(const GameManager& other) = delete;

public:
	//�R���e���c�̓ǂݍ���
	void LoadContent();
	//�R���e���c�̍폜
	void UnLoadContent();
	//�����_���[�̎擾
	virtual Renderer2DPtr GetRenderer2D() override;
	//�C���v�b�g�X�e�C�g�̎擾
	virtual InputStatePtr GetInputState() override;
	//�V�[����Enum�̎擾
	virtual EnumRapPtr<SceneName> GetSceneEnum() override;
	//�v���C���[�p�����[�^�[�̎擾
	virtual Player_Parameter GetPlayerParameter() override;
	//�v���C���[�p�����[�^�[�̐ݒ�				
	virtual void SetPlayerParameter(const Player_Parameter& parameter) override;

protected:
	//�I������
	void Finalize() override;
private:
	Renderer2DPtr p_Renderer2D;		//�����_���[
	InputStatePtr p_InputState;		//�C���v�b�g�X�e�C�g
	EnumRapPtr<SceneName> p_SceneEnum;	//�V�[��Enum
	Player_Parameter	m_Parameter;	//�v���C���[�p�����[�^�[
};

#endif // !GAMEMANAGER_H_