#ifndef ENEMY_BASE_H_
#define ENEMY_BASE_H_

#include "../../../../ActorContains/Actor/Actor.h"

//��s�錾
class Enemy_StateManager;

//�G�l�~�[���N���X
class Enemy_Base :public Actor
{
public:
	//�R���X�g���N�^
	Enemy_Base(
		const IWorldPtr& world,
		const ActorName& name,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const ITexturePtr& texture,
		const IBodyPtr& body = std::make_shared<DammyBody>()
		);
	//���z�f�X�g���N�^
	virtual ~Enemy_Base() {}

protected:
	//�X�V
	virtual void onUpdate(float deltaTime) override;
	//�`��
	virtual void onDraw() const override;
	//�Փ˂���
	virtual void onCollide(Actor& other) override;

protected:
	Enemy_StateManager* p_Enemy_StateManager;	//�X�e�[�g�}�l�[�W���[
};
#endif // !ENEMY_H_
