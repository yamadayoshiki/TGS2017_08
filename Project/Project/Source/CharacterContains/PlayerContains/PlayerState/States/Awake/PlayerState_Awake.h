#ifndef PLAYERSTATE_AWAKE_H_
#define PLAYERSTATE_AWAKE_H_

#include"../../PlayerState.h"

//アーム解放
class PlayerState_Awake:public  PlayerState
{
public:
	//コンストラクタ
	PlayerState_Awake(GSvector2& positon,GSmatrix4& matrix,IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init(Actor& actor)override;
	//更新処理
	virtual void update(Actor& actor, float deltaTaime)override;
	//衝突判定
	virtual void collide(const Actor& other)override;
	//終了処理
	virtual void end()override;
};
#endif // !PLAYERSTATE_AWAKE_H_
