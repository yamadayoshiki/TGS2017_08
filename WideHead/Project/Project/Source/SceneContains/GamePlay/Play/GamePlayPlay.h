#ifndef GAMEPLAYPLAY_H_
#define GAMEPLAYPLAY_H_
#include "../../Scene/ChildScene.h"
class GamePlayPlay : public ChildScene
{
public:
	GamePlayPlay();

protected:
	// �X�V     
	virtual void OnUpdate(float deltaTime) override;
};
#endif // !GAMEPLAYPLAY_H_
