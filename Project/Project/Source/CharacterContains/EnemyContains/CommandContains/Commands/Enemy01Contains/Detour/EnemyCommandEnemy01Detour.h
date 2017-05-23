#ifndef ENEMYCOMMANDENEMY01DETOUR_H_
#define ENEMYCOMMANDENEMY01DETOUR_H_

#include "../../AlongWallMove/EnemyCommandAlongWallMove.h"

//�ǂ�����ŋ󂢂Ă�}�X�ɁA�ǉ����ɍŒZ�̉�]�����ňړ�
class EnemyCommandEnemy01Detour : public EnemyCommandAlongWallMove
{
public:
	//�R���X�g���N�^
	EnemyCommandEnemy01Detour(
		const EnemyBasePtr& enemy);
	//�f�X�g���N�^
	~EnemyCommandEnemy01Detour();

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) override;
	//�ڕW�n�_�ɓ����������A�N�V����
	virtual void ArriveReaction() override;
	//�ڕW�n�_�̐ݒ�
	virtual void SetTargetPos() override;
	//�ڕW�n�_�Ǘ��̎擾
	TargetPosition GetTargetPositionManager();

	//�v���C���[�ƍ��W������v���Ă��邩
	void CheckAxisEnemyToPlayer();

protected:
	bool m_AxisChangeFlag;
};

#endif // !ENEMYCOMMANDENEMY01DETOUR_H_