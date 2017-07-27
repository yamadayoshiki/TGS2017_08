#ifndef ESGENERATE_H_
#define ESGENERATE_H_
#include "../Base/EnemyStateBase.h"
#include "../../../../../Utility/Sound/SoundName.h"
class ESGenerate : public EnemyStateBase
{
public:
	//コンストラクタ
	ESGenerate(
		const EnemyBasePtr & enemy,
		const SoundName se,
		const float forwardDis,
		const int charaNum,
		const int lagTime = 0);

public:
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;
	//終了
	virtual void end() override;

private:
	void Generate();

private:
	SoundName m_SE;
	float m_ForwardDis;
	int m_CharaNumber;	//生成するキャラクターの番号
	float m_LagTime;		//生成タイミング
	float m_Timer;
};
#endif // !ESCHANT_H_
