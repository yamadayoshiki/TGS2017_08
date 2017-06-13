#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include"../Scene/Scene.h"

class World;

class GameOver : public Scene
{
public:
	//�R���X�g���N�^
	GameOver(const IGameManagerPtr& gameManager);

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	// �`��     
	virtual void OnDraw()const;
};

#endif // !GAMEOVER_H_
