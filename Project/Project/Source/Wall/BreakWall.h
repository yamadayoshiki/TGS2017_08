#ifndef BREAK_WALL
#define BREAK_WALL

#include"../CharacterContains/EnemyContains/Enemys/Base/EnemyBase.h"

class BreakWall : public EnemyBase
{
public:
	BreakWall(
		IWorld* world,
		const GSvector2&  position,
		const IGameManagerPtr& gameManager);
	//������
	virtual void initialize() override;
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() override;
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() override;
	virtual void onDraw() const override;

	virtual ActorPtr clone(const GSvector2& position, const FourDirection& front = FourDirection(FourDirectionName::None)) override;

private:

};
#endif // !BREAK_WALL