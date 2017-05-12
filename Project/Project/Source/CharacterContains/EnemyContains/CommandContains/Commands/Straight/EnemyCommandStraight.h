#ifndef ENMYCOMMANDSTRAIGHT_H_
#define ENMYCOMMANDSTRAIGHT_H_

#include "../Base/EnemyCommandBase.h"

//���i�N���X
class EnemyCommandStraight :public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandStraight(const EnemyBasePtr& enemy, GSvector2 velocity);
	//�X�V
	virtual void Update(float deltaTime) override;
	//�I��
	virtual void Finalize() override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//���ʂɕǂ��������ꍇ�̃��A�N�V����
	virtual void HitWallReaction();
	//�܂�Ԃ�
	void TurnBack();
};

#endif // !ENMYCOMMANDSTRAIGHT_H_
