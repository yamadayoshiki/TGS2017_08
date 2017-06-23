#ifndef GAMETUTORIAL_H_
#define GAMETUTORIAL_H_

#include "../Scene/Scene.h"

class GameTutorial : public Scene
{
public:
	GameTutorial(const IGameManagerPtr& gameManager);

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	// �`��     
	virtual void OnDraw()const;
	//�I��
	virtual void End()override;
};

#endif // !GAAMETUTORIAL_H_
