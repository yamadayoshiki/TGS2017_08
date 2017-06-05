#ifndef ENEMYCOMMANDMOVEBASE_H_
#define ENEMYCOMMANDMOVEBASE_H_

#include "../../../Base/EnemyCommandBase.h"

//��s�錾
class Map;

//�����̂���R�}���h�̊��N���X
class EnemyCommandMoveBase : public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandMoveBase(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) override;

protected:
	//�ڕW�n�_�ɓ����������A�N�V����
	virtual void ArriveReaction() = 0;
	//���̖ڕW�n�_��ݒ肷��
	virtual void SetNextTargetPos() = 0;

protected:
	MapType m_Type;					//�}�b�v�̃^�C�v
	GSvector2 m_NextTargetPos;		//�ڕW�n�_
};

#endif // !ENEMYCOMMANDMOVEBASE_H_
