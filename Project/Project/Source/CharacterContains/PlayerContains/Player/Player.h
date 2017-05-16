#ifndef PLAYER_H_
#define PLAYER_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"Player_Parameter.h"
#include"../PlayerState/PlayerStateManager.h"
#include"../../../WorldContains/IWorld.h"
#include"../Arm/ArmPtr.h"
#include"../../CharacterManagerContains/CharacterManager/CharacterManager.h"
#include<memory>

class Renderer2D;

class Player :public Actor, public std::enable_shared_from_this<Player>
{
public:
	//�R���X�g���N�^
	Player(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager);
	//�f�X�g���N�^
	~Player();
	//
	virtual void initialize()override;
	//�X�V����
	virtual void onUpdate(float deltaTime)override;
	//�`�揈��
	virtual void onDraw()const override;
	//�Փ˔���
	virtual void onCollide(Actor& other)override;
	
	//�v���C���[�p�����[�^�[�̎擾
	Player_Parameter getParameter();

private:
	//��ԊǗ�
	PlayerStateManager*		mStateManager;
	//
	CharacterManager*		p_CharacterManager;
	//�����_���[
	Renderer2DPtr			p_Renderer;
	//�v���C���[�p�����^�[
	Player_Parameter		m_Parameter;
	//��]
	float					angle;
	//�q
	ArmPtr				child;
};
#endif // !PLAYER_H_
