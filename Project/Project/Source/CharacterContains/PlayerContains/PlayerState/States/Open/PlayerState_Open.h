#ifndef PLAYERSTATE_OPEN_H_
#define PLAYERSTATE_OPEN_H_

#include"../../PlayerState.h"

//アーム解放
class PlayerState_Open:public  PlayerState
{
public:
	//コンストラクタ
	PlayerState_Open(const PlayerPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init()override;
	//更新処理
	virtual void update(float deltaTaime)override;
	//衝突判定
	virtual void collide(const Actor& other)override;
	//終了処理
	virtual void end()override;
};
#endif // !PLAYERSTATE_OPEN_H_
