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
	//�R���X�g���N�^
	Wall(IWorld* world,const GSvector2 position );
	//�X�V
	void Update(float deltaTime);
	//�`��
	void Draw() const;
	//�Փ˔���
	void Collide(Actor&);
	//�I��
	void End();
private:
	

};

#endif // !WALL_H_
