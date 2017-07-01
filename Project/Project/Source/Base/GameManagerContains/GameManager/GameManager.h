#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "../IGameManager.h"

class GameManager :public IGameManager
{
public:
	//�R���X�g���N�^
	GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState,const ScorePtr& score);
	//���z�f�X�g���N�^
	virtual ~GameManager() { Finalize(); }
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
	Renderer2DPtr GetRenderer2D() override;
	//�`��Ǘ��̎擾
	DrawOrderManagerSPtr GetDrawOrderManagerPtr();
	//�C���v�b�g�X�e�C�g�̎擾
	virtual InputStatePtr GetInputState() override;
	//�V�[����Enum�̎擾
	virtual EnumRapPtr<SceneName> GetSceneEnum() override;
	//�v���C���[�p�����[�^�[�̎擾
	virtual Player_Parameter& GetPlayerParameter() override;
	//�v���C���[�p�����[�^�[�̐ݒ�				
	virtual void SetPlayerParameter(const Player_Parameter& parameter) override;
	//�X�R�A�̎擾
	virtual ScorePtr GetScore()override;

	void set_MapOrder(int MapOrder)override;
	int get_MapOrder()const override;

protected:
	//�I������
	void Finalize() override;
private:
	Renderer2DPtr p_Renderer2D;					//�����_���[
	DrawOrderManagerSPtr p_DrawOrderManager;	//�`��Ǘ�
	InputStatePtr p_InputState;			//�C���v�b�g�X�e�C�g
	ScorePtr	  p_Score;				//�X�R�A
	EnumRapPtr<SceneName> p_SceneEnum;	//�V�[��Enum
	Player_Parameter	m_Parameter;	//�v���C���[�p�����[�^�[
	int MapOrder_;
};

#endif // !GAMEMANAGER_H_