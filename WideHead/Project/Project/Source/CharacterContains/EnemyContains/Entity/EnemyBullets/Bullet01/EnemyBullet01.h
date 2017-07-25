#ifndef ENEMYBULLET01_H_
#define ENEMYBULLET01_H_

#include "../../Enemys/Base/EnemyBase.h"

//���i�e
class EnemyBullet01 : public EnemyBase
{
public:
	//�R���X�g���N�^
	EnemyBullet01(
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
};

#endif // !ENEMYBULLET01_H_
