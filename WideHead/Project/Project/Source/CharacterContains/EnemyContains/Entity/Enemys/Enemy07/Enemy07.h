#ifndef ENEMY07_H_
#define ENEMY07_H_

#include "../Base/EnemyBase.h"

//ノコノコ
class Enemy07 : public EnemyBase
{
public:
	//コンストラクタ
	Enemy07(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const IGameManagerPtr& gameManager,
		const std::string fileName = "");
	//デストラクタ
	~Enemy07();
	//csvで生成(使用時継承先でoverride)
	virtual ActorPtr CsvGenerate(const int x, const int y, const int csvparam) override;

protected:
	//各種固有のコマンドの設定
	virtual void SetUpCommand() override;
	//各種固有のStateの設定
	virtual void SetUpState() override;
	//描画
	virtual void onDraw() const override;

protected:
	std::string m_FileName;	//巡回座標csvのファイルの名前
};

#endif // !ENEMY07_H_
