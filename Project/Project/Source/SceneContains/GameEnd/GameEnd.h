#ifndef GAMEEND_H_
#define GAMEEND_H_

#include "../Scene/Scene.h"

class World;

//�Q�[����
class GameEnd : public Scene
{
public:
	// �R���X�g���N�^    
	GameEnd(const IGameManagerPtr& gameManager);
protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
};

#endif