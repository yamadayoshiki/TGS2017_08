#ifndef ENEMYBASE_H_
#define ENEMYBASE_H_

#include "../../../../../ActorContains/State/Base/State.h"
#include "../../../CommandContains/CommandManagers/Interface/IEnemyCommandManagerPtr.h"
#include "../../../../../ActorContains/HitPoint/HitPoint.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../ActorContains/Actor/Actor.h"
#include "../../../PlayerWatch/PlayerWatchPtr.h"
#include "../../../StateContains/StateManager/EnemyStateManagerPtr.h"
#include "../../../../../Map/MapType.h"
#include <map>

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
		const int maxHp,												//�q�b�g�|�C���g
		const MapType type,												//�ړ��}�b�v�^�C�v
		const IGameManagerPtr& gameManager,								//�Q�[���}�l�[�W��
		const ITexturePtr& texture,										//�e�N�X�`��
		const IBodyPtr& body = std::make_shared<Body::NullBody>());			//�Փ˔���}�`

																			//�f�X�g���N�^
	virtual ~EnemyBase();
	//������
	virtual void initialize() override;
	//�X�e�[�g�}�l�[�W���[���擾����
	EnemyStateManager* GetStateManager();
	//�R�}���h�}�l�[�W���[���擾����
	IEnemyCommandManager* GetCommandManager();
	//�q�b�g�|�C���g���擾����
	HitPoint& GetHitPoint();
	//�|���邩�|���Ȃ���
	bool CanDead();
	//�v���C���[�Ď��N���X���擾����
	const PlayerWatch* GetPlayerWatch() const;
	//�������擾
	FourDirection GetDirection() const;
	//������ݒ�
	void SetDirection(FourDirection dir);
	//�ړ��}�b�v�^�C�v���擾
	MapType GetMapType() const override;

	//�e�N�X�`���̐؂�ւ�
	void Settexture(const std::string textureName);

protected:
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() {}
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() {}
	//�X�V
	virtual void onUpdate(float deltaTime) override;
	//�`��
	virtual void onDraw() const override;
	//�Փ˂���
	virtual void onCollide(Actor& other) override;
	//���b�Z�[�W����
	virtual void onMessage(EventMessage message, void* param) override;

protected:
	MapType m_MapType;								//�ړ��}�b�v�^�C�v
	HitPoint m_HitPoint;							//�q�b�g�|�C���g
	PlayerWatchUPtr p_PlayerWatch;					//�v���C���[�Ď�
	EnemyStateManagerUPtr p_StateManager;			//�X�e�[�g�}�l�[�W���[
	IEnemyCommandManagerUPtr p_CommandManager;		//�R�}���h�}�l�[�W���[

	std::map < std::string, ITexturePtr > m_TextureMap;	//�e�N�X�`���؂�ւ��悤�}�b�v

	FourDirection m_FourDirection;					//����
};
#endif