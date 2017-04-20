#ifndef PLAYER_H_
#define PLAYER_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../PlayerState/PlayerStateManager.h"
#include"../../../WorldContains/IWorld.h"
#include<memory>

class GameManager;
class Renderer2D;

class Player :public Actor
{
public:
	//�R���X�g���N�^
	Player(IWorld* world,const GSvector2& position,GameManager* gameManager);
	//�f�X�g���N�^
	~Player();
	//�X�V����
	virtual void onUpdate(float deltaTime)override;
	//�`�揈��
	virtual void onDraw()const override;
	//�Փ˔���
	virtual void onCollide(Actor& other)override;

private:
	//�Q�[���Ǘ���
	GameManager*			p_GameManager;
	//��ԊǗ�
	PlayerStateManager*		mStateManager;
	//�����_���[
	Renderer2D*				p_Renderer;
	//��]
	float angle;
};
#endif // !PLAYER_H_
