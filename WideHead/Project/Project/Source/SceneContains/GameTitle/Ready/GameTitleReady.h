#ifndef GAMETITLEREADY_H_
#define GAMETITLEREADY_H_
#include "../../Scene/ChildScene.h"

class GameTitleReady : public ChildScene
{
public:
	GameTitleReady();

protected:
	// �J�n     
	virtual void OnStart() override;
	// �X�V     
	virtual void OnUpdate(float deltaTime) override;
	//�I��
	virtual void OnEnd()override;
};
#endif // !GAMETITLEREADY_H_
