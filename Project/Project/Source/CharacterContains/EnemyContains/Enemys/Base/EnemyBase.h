#ifndef ENEMYBASE_H_
#define ENEMYBASE_H_

#include "../../../../ActorContains/State/Base/State.h"
#include "../../StateContains/StateManager/EnemyStateManager.h"
#include "../../CommandContains/CommandManagers/Interface/IEnemyCommandManagerPtr.h"

//��s�錾
class EnemyStateManager;

//�G�l�~�[���N���X
class EnemyBase :public Actor, public std::enable_shared_from_this<EnemyBase>
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
	IEnemyCommandManagerPtr GetCommandManager();

protected:
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() = 0;
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() = 0;
	//�X�V
	virtual void onUpdate(float deltaTime) override;
	//�`��
	virtual void onDraw() const override;
	//�Փ˂���
	virtual void onCollide(Actor& other) override;
	//���b�Z�[�W����
	virtual void onMessage(EventMessage message, void* param) override;

protected:
	float m_Speed;									//�X�s�[�h
	EnemyStateManager* p_StateManager;				//�X�e�[�g�}�l�[�W���[
	IEnemyCommandManagerPtr p_CommandManager;		//�R�}���h�}�l�[�W���[
};
#endif