#ifndef GAMETITLESELECT_H_
#define GAMETITLESELECT_H_
#include "../../Scene/ChildScene.h"
class GameTitleSelect : public ChildScene
{
public:
	GameTitleSelect();

protected:
	// �J�n     
	virtual void OnStart() override;
	// �X�V     
	virtual void OnUpdate(float deltaTime) override;
	//�I��
	virtual void OnEnd()override;
};
#endif // !GAMETITLESELECT_H_
