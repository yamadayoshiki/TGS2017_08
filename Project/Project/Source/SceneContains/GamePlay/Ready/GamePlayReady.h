#ifndef GAMEPLAYREADY_H_
#define GAMEPLAYREADY_H_
#include "../../Scene/ChildScene.h"
//�Q�[���v���C����
class GamePlayReady : public ChildScene
{
public:
	GamePlayReady();
	~GamePlayReady();

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
#endif // !GAMEPLAYREADY_H_