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
	EnemyCommandStraight(const EnemyBasePtr& enemy, const FourDirection front, const MapType type);
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
	//���ʂɕǂ����邩
	bool CheckFrontWall();
	//���̖ڕW�n�_��ݒ肷��
	void SetNextTargetPos();

protected:
	GSvector2 m_NextTargetPos;		//���̖ڕW�n�_
	FourDirection m_CurFront;		//���݌����Ă������
	MapType m_Type;
};

#endif // !ENMYCOMMANDSTRAIGHT_H_
