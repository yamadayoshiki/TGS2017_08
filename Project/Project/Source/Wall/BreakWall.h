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
	//初期化
	virtual void initialize() override;
	//各種固有のコマンドの設定
	virtual void SetUpCommand() override;
	//各種固有のStateの設定
	virtual void SetUpState() override;
	virtual void onDraw() const override;

	virtual ActorPtr clone(const GSvector2& position, const FourDirection& front = FourDirection(FourDirectionName::None)) override;

private:

};
#endif // !BREAK_WALL