#ifndef ESGENERATE_H_
#define ESGENERATE_H_
#include "../Base/EnemyStateBase.h"
#include "../../../../../Utility/Sound/SoundName.h"
class ESGenerate : public EnemyStateBase
{
public:
	//�R���X�g���N�^
	ESGenerate(
		const EnemyBasePtr & enemy,
		const SoundName se,
		const float forwardDis,
		const int charaNum,
		const int lagTime = 0);

public:
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
	//�I��
	virtual void end() override;

private:
	void Generate();

private:
	SoundName m_SE;
	float m_ForwardDis;
	int m_CharaNumber;	//��������L�����N�^�[�̔ԍ�
	float m_LagTime;		//�����^�C�~���O
	float m_Timer;
};
#endif // !ESCHANT_H_
