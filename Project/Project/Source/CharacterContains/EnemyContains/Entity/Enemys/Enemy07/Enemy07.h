#ifndef ENEMY07_H_
#define ENEMY07_H_

#include "../Base/EnemyBase.h"

//�m�R�m�R
class Enemy07 : public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy07(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const IGameManagerPtr& gameManager);
	//�f�X�g���N�^
	~Enemy07();
	//�N���[������(�g�p���p�����override)
	virtual ActorPtr clone(
		const GSvector2& position,
		const FourDirection& front = FourDirection(FourDirectionName::None)) override;

protected:
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() override;
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() override;
	//�`��
	virtual void onDraw() const override;
};

#endif // !ENEMY07_H_
