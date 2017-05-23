#ifndef ENMYCOMMANDSTRAIGHT_H_
#define ENMYCOMMANDSTRAIGHT_H_

#include "../Base/EnemyCommandBase.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Map/MapType.h"

//���i�N���X
class EnemyCommandStraight :public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandStraight(
		const EnemyBasePtr& enemy,
		const MapType type);
	//�I��
	virtual void Finalize() override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) override;
	//�ڕW�n�_�ɓ����������A�N�V����
	virtual void ArriveReaction();
	//���ʂɕǂ��������ꍇ�̃��A�N�V����
	virtual void HitWallReaction();
	//���̖ڕW�n�_��ݒ肷��
	void SetNextTargetPos();

protected:
	GSvector2 m_NextTargetPos;		//���̖ڕW�n�_
	MapType m_Type;					//�}�b�v�^�C�v
};

#endif
