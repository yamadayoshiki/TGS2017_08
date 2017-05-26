#ifndef ENEMYBASE_H_
#define ENEMYBASE_H_

#include "../../../../ActorContains/State/Base/State.h"
#include "../../StateContains/StateManager/EnemyStateManager.h"
#include "../../CommandContains/CommandManagers/Interface/IEnemyCommandManagerPtr.h"
#include "../../../../ActorContains/HitPoint/HitPoint.h"
#include "../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../ActorContains/Actor/Actor.h"

//��s�錾
class EnemyStateManager;
class PlayerWatch;

//�G�l�~�[���N���X
class EnemyBase :public Actor, public std::enable_shared_from_this<EnemyBase>
{
public:
	//�R���X�g���N�^
	EnemyBase(
		IWorld* world,													//���[���h
		const ActorName& name,											//���O
		const GSvector2& position,										//���W
		const FourDirection front,										//����
		const float speed,												//�ړ����x
		const int maxHp,												//�q�b�g�|�C���g
		const IGameManagerPtr& gameManager,								//�Q�[���}�l�[�W��
		const ITexturePtr& texture,										//�e�N�X�`��
		const IBodyPtr& body = std::make_shared<DammyBody>());			//�Փ˔���}�`
																		//�f�X�g���N�^
	virtual ~EnemyBase();
	//������
	virtual void initialize() override;
	//�X�e�[�g�}�l�[�W���[���擾����
	EnemyStateManager* GetStateManager();
	//�R�}���h�}�l�[�W���[���擾����
	IEnemyCommandManagerPtr GetCommandManager();
	//�q�b�g�|�C���g���擾����
	HitPoint& GetHitPoint();
	//�|���邩�|���Ȃ���
	bool CanDead();
	//�v���C���[�Ď��N���X���擾����
	PlayerWatch* GetPlayerWatch();
	//�����Ǘ�
	FourDirection GetDirection() const;
	void SetDirection(FourDirection dir);

protected:
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand(){}
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState(){}
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
	HitPoint m_HitPoint;							//�q�b�g�|�C���g
	PlayerWatch* p_PlayerWatch;						//�v���C���[�Ď�
	EnemyStateManager* p_StateManager;				//�X�e�[�g�}�l�[�W���[
	IEnemyCommandManagerPtr p_CommandManager;		//�R�}���h�}�l�[�W���[

	FourDirection m_FourDirection;					//����
};
#endif