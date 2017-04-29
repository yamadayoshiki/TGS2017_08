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
	// �V�[���̏I���̎擾
	virtual bool IsEndScene() override;
	// �V�[���̏I��
	virtual void EndScene(bool end = false) override;

protected:
	//�I������
	void Finalize() override;
private:
	Renderer2DPtr p_Renderer2D;	//�����_���[
	InputStatePtr p_InputState;	//�C���v�b�g�X�e�C�g
	bool m_IsEnd;				//�V�[���̏I��
};

#endif // !GAMEMANAGER_H_