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
	//初期化
	virtual void onInitialize() override;
	//各種固有のコマンドの設定
	virtual void SetUpCommand() override;
	//各種固有のStateの設定
	virtual void SetUpState() override;
	virtual void onDraw() const override;
	//csvで生成(使用時継承先でoverride)
	virtual ActorPtr CsvGenerate(const int x, const int y, const int csvparam) override;
private:

};
#endif // !BREAK_WALL