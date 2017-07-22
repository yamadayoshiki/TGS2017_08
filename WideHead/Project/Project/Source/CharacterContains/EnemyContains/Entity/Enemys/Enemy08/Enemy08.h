#ifndef ENEMY08_H_
#define ENEMY08_H_

#include "../Base/EnemyBase.h"

//�e���o���G
class Enemy08 : public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy08(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const IGameManagerPtr& gameManager);
	//�f�X�g���N�^
	~Enemy08();
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