#ifndef ENEMYCOMMANDSTRAIGHTTOUCHWALL_H_
#define ENEMYCOMMANDSTRAIGHTTOUCHWALL_H_

#include "../Straight/EnemyCommandStraight.h"

//�ǂɐG���܂Œ��i
class EnemyCommandStraightTW : public EnemyCommandStraight
{
public:
	//�R���X�g���N�^
	EnemyCommandStraightTW(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//���̖ڕW�n�_��ݒ肷��
	virtual void SetNextTargetPos() override;
};



#endif // !ENEMYCOMMANDSTRAIGHTTOUCHWALL_H_
