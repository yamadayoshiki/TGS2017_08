#ifndef PLAYERSTATE_IDOL_H_
#define PLAYERSTATE_IDOL_H_

#include"PlayerState_MoveBase.h"

//待機(通常)状態
class PlayerState_Idol:public PlayerState_MoveBase
{
public:
	//コンストラクタ
	PlayerState_Idol(GSvector2& pos);
	//各状態独自の初期化
	virtual void onUniqueInit(Actor& actor)override;
	//更新処理
	virtual void onUpdate(Actor& actor,float deltaTime){}
	//衝突処理
	virtual void onCollide(Actor& other){}
	//終了処理
	virtual void onEnd(){}
	//入力処理
	virtual void onInput(){}
};
#endif // !PLAYERSTATE_IDOL_H_

