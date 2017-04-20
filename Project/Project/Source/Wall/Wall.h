#ifndef WALL_H_
#define WALL_H_

#include<GSvector2.h>

#include"../Base/GameManagerContains/GameManager/GameManager.h"
#include"../ActorContains/Actor/Actor.h"

class IWorld;
class Map;

class Wall
{
public:
	//コンストラクタ
	Wall(IWorld* world,const GSvector2 position );
	//更新
	void Update(float deltaTime);
	//描画
	void Draw() const;
	//衝突判定
	void Collide(Actor&);
	//終了
	void End();
private:
	

};

#endif // !WALL_H_
