#ifndef ENEMY11_H_
#define ENEMY11_H_
#include "../Base/EnemyBase.h"

//�˂����ޓG
class Enemy11 : public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy11(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const IGameManagerPtr& gameManager);
	//�f�X�g���N�^
	~Enemy11();
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

#endif // !ENEMY11_H_
