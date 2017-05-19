#ifndef ENEMY04_H_
#define ENEMY04_H_

#include "../Base/EnemyBase.h"
struct FourDirection;

class Enemy04:public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy04(
		IWorld* world,
		const GSvector2& position,
		FourDirection& front,
		const IGameManagerPtr& gameManager);
protected:
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() override;
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() override;
	//�`��
	virtual void onDraw() const override;
};

#endif // !ENEMY04_H_
