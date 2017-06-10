#ifndef ENEMY06_H_
#define ENEMY06_H_

#include "../Base/EnemyBase.h"

//�q�@�𐶐�����G�l�~�[
class Enemy06: public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy06(
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

#endif // !ENEMY06_H_