#ifndef GAMETUTORIALPLAY_H_
#define GAMETUTORIALPLAY_H_
#include "../../Scene/ChildScene.h"
class GameTutorialPlay : public ChildScene
{
public:
	GameTutorialPlay();

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
