#ifndef GAMEPLAYPAUSE_H_
#define GAMEPLAYPAUSE_H_
#include "../../Scene/ChildScene.h"
//�Q�[����ʃ|�[�Y
class GamePlayPause : public ChildScene
{
public:
	GamePlayPause();

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
#endif // !GAMEPLAYPAUSE_H_
