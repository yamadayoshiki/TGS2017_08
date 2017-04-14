#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "../IGameManager.h"

class GameManager:public IGameManager
{
public:
	//�R���X�g���N�^
	GameManager(Renderer2D* renderer2D);
	//�R���e���c�̓ǂݍ���
	void LoadContent() override;
	//�R���e���c�̍폜
	void UnLoadContent() override;
	//�R�s�[�֎~
	GameManager& operator = (const GameManager& other) = delete;
	GameManager(const GameManager& other) = delete;

public:
	//�����_���[�̎擾
	Renderer2D* GetRenderer2D() override;

protected:
	//�I������
	void Finalize() override;

private:
	Renderer2D* p_Renderer2D;//�����_���[
};

#endif // !GAMEMANAGER_H_