#ifndef GAMEPLAYPLAY_H_
#define GAMEPLAYPLAY_H_
#include "../../Scene/ChildScene.h"
class GamePlayPlay : public ChildScene
{
public:
	GamePlayPlay();

protected:
	// �J�n     
	virtual void OnStart() override;
	// �X�V     
	virtual void OnUpdate(float deltaTime) override;
	// �`��     
	virtual void OnDraw()const override;
	//�I��
	virtual void OnEnd()override;
};
#endif // !GAMEPLAYPLAY_H_
