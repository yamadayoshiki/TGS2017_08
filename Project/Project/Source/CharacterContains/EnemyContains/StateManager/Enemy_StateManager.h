#ifndef ENEMY_STATEMANAGER_H_
#define ENEMY_STATEMANAGER_H_

#include "../../../ActorContains/State/Base/StateMgr.h"

//��s�錾
struct GSvector2;
struct GSmatrix4;

class Enemy_StateManager:public StateMgr
{
public:
	// �f�t�H���g�R���X�g���N�^
	Enemy_StateManager();
	// �R���X�g���N�^
	Enemy_StateManager(GSvector2& pos, GSmatrix4& mat);
};

#endif // !ENEMY_STATEMANAGER_H_
