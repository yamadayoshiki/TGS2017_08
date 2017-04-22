#ifndef PLAYER_H_
#define PLAYER_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../PlayerState/PlayerStateManager.h"
#include"../../../WorldContains/IWorld.h"
#include<memory>

class Renderer2D;

class Player :public Actor
{
public:
	//�R���X�g���N�^
	Player(const IWorldPtr& world, const GSvector2& position, const IGameManagerPtr& gameManager);
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
	IGameManagerPtr			p_GameManager;
	//��ԊǗ�
	PlayerStateManager*		mStateManager;
	//�����_���[
	Renderer2DPtr				p_Renderer;
	//��]
	float angle;
};
#endif // !PLAYER_H_
