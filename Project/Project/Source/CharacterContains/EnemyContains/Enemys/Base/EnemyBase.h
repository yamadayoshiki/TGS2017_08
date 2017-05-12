#ifndef ENEMYBASE_H_
#define ENEMYBASE_H_

#include "../../../../ActorContains/State/Base/State.h"
#include "../../StateContains/StateManager/EnemyStateManager.h"
#include "../../CommandContains/CommandManager/EnemyCommandManager.h"

//��s�錾
class EnemyStateManager;

//�G�l�~�[���N���X
class EnemyBase :public Actor, std::enable_shared_from_this<EnemyBase>
{
public:
	//�R���X�g���N�^
	EnemyBase(
		IWorld* world,
		const ActorName& name,
		const GSvector2& position,
		const float speed,
		const IGameManagerPtr& gameManager,
		const ITexturePtr& texture,
		const IBodyPtr& body = std::make_shared<DammyBody>());
	//�f�X�g���N�^
	virtual ~EnemyBase();
	//������
	virtual void initialize() override;
	//�X�e�[�g�}�l�[�W���[���擾����
	EnemyStateManager* GetStateManager();
	//�R�}���h�}�l�[�W���[���擾����
	EnemyCommandManager* GetCommandManager();

protected:
	//�X�V
	virtual void onUpdate(float deltaTime) override;
	//�`��
	virtual void onDraw() const override;
	//�Փ˂���
	virtual void onCollide(Actor& other) override;

protected:
	float m_Speed;								//�X�s�[�h
	EnemyStateManager* p_StateManager;			//�X�e�[�g�}�l�[�W���[
	EnemyCommandManager* p_CommandManager;		//�R�}���h�}�l�[�W���[
};
#endif