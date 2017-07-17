#ifndef BREAK_WALL
#define BREAK_WALL

#include"../CharacterContains/EnemyContains/Entity/Enemys/Base/EnemyBase.h"

class BreakWall : public EnemyBase
{
public:
	BreakWall(
		IWorld* world,
		const GSvector2&  position,
		const IGameManagerPtr& gameManager);
	//������
	virtual void onInitialize() override;
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() override;
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() override;
	virtual void onDraw() const override;
	//csv�Ő���(�g�p���p�����override)
	virtual ActorPtr CsvGenerate(const int x, const int y, const int csvparam) override;
private:

};
#endif // !BREAK_WALL