#ifndef GAMETITLE_H_
#define GAMETITLE_H_

#include "../Scene/Scene.h"

//�^�C�g���V�[��
class GameTitle : public Scene
{
public:
	// �R���X�g���N�^    
	GameTitle(const IGameManagerPtr& gameManager);

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	// �`��     
	virtual void OnDraw()const;
};

#endif