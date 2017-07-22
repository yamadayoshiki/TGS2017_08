#ifndef ENEMY04_H_
#define ENEMY04_H_

#include "../Base/EnemyBase.h"

struct FourDirection;

//3�񋲂܂��(�������)��1�}�X�ړ�
class Enemy04 :public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy04(
		IWorld* world,
		const GSvector2& position,
		const FourDirection& front,
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