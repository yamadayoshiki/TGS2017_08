#ifndef ARM_H_
#define ARM_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"

class Arm:public Actor
{
public:
	//�R���X�g���N�^
	Arm(const IWorldPtr& world, GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager);
	//�f�X�g���N�^
	~Arm();
	//�X�V����
	virtual void onUpdate(float deltaTime)override;
	//�`�揈��
	virtual void onDraw()const override;
	//�Փ˔���
	virtual void onCollide(Actor& other)override;
	//�Փ˂��Ă�����Ԃ�
	bool is_Hit();
	//���W�̐ݒ�
	void setPosition(GSvector2 position);
	//�s��
	void setMatrix(GSmatrix4 matrix);
	//��]�p�x
	void setAngle(float angle);

private:
	//��]
	float		m_Angle;
	//
	bool		mHitFlag {false};
};
#endif // !ARM_H_
