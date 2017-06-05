#ifndef ENEMY01_H_
#define ENEMY01_H_

#include "../Base/EnemyBase.h"

//�ǐՂ���G
class Enemy01 : public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy01(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const IGameManagerPtr& gameManager);

	//�N���[������(�g�p���p�����override)
	virtual ActorPtr clone(const GSvector2& position, const FourDirection& front = FourDirection(FourDirectionName::None)) override;

protected:
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() override;
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() override;
	//�`��
	virtual void onDraw() const override;
};

#endif
