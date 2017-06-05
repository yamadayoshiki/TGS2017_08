#ifndef ENEMYCOMMANDRUSH_H_
#define ENEMYCOMMANDRUSH_H_

#include "../../../Base/EnemyCommandBase.h"

//�ˌ�
class EnemyCommandRush : public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandRush(
		const EnemyBasePtr& enemy,
		const MapType type,
		const TurnDirection turnDirection);
	//�f�X�g���N�^
	~EnemyCommandRush();
	//�I��
	virtual void Finalize() override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) override;
};

#endif
