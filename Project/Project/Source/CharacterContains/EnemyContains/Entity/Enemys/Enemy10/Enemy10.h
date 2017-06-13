#ifndef ENEMY10_H_
#define ENEMY10_H_

#include "../Base/EnemyBase.h"

//�G�l�~�[06�ɐ��������q�@
class Enemy10 : public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy10(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const IGameManagerPtr& gameManager);

	//csv�Ő���(�g�p���p�����override)
	virtual ActorPtr CsvGenerate(const int x, const int y, const int csvparam) override;
protected:
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() override;
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() override;
	//�`��
	virtual void onDraw() const override;
};
#endif