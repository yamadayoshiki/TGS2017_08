#ifndef ENEMYSTATERUSH_H_
#define ENEMYSTATERUSH_H_

#include "../../Base/EnemyStateBase.h"

//�ˌ�
class EnemyStateRush :public EnemyStateBase
{
public:
	//�R���X�g���N�^
	EnemyStateRush(const EnemyBasePtr& enemy,const float speed);

protected:
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
	//�I��
	virtual void end() override;
	//���b�Z�[�W����
	virtual void OnHandleMessage(EventMessage message, void* param) override;
protected:
	float m_Speed;		//�X�s�[�h
};

#endif
