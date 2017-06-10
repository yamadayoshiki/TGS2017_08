#ifndef ENEMY05_H_
#define ENEMY05_H_

#include "../Base/EnemyBase.h"

//��������������G
class Enemy05 : public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy05(
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

#endif // !ENEMY05_H_

