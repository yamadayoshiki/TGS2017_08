#ifndef ENEMYCOMMANDENEMY09STANDBY_H_
#define ENEMYCOMMANDENEMY09STANDBY_H_

#include "../../Base/EnemyCommandBase.h"
#include <map>

class FrontChipList;

class EnemyCommandEnemy09Standby : public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandEnemy09Standby(
		const EnemyBasePtr& enemy);
	//デストラクタ
	~EnemyCommandEnemy09Standby();

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の更新
	virtual void OnUpdate(float deltaTime) override;

protected:
	//プレイヤーがX軸もしくはY軸で重なっているか
	bool IsAxisOverlap();

private:
	//指定方向の壁マスまでの距離の設定
	void SetSpeaceNum(const FourDirectionName name);

protected:
	FrontChipList* p_FrontChipList;							//前方マス管理
	std::unordered_map<FourDirection, int> m_SpeaceNumMap;	//方向ごとの壁マスまでの数
};

#endif // !ENEMYCOMMANDENEMY09STANDBY_H_