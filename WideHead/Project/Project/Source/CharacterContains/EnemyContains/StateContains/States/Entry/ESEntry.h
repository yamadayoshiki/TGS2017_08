#ifndef ESENTRY_H_
#define ESENTRY_H_
#include "../Base/EnemyStateBase.h"
class AnimationTexture;
class ESEntry : public EnemyStateBase
{
public:
	//コンストラクタ
	ESEntry(const EnemyBasePtr& enemy);

public:
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;
	//終了
	virtual void end() override;
	
private:
	std::shared_ptr<AnimationTexture> p_EntrySmork;
	int m_Timer;
};
#endif // !ESENTRY_H_
