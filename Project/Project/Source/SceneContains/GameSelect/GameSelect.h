#ifndef GAMESELECT_H_
#define GAMESELECT_H_

#include "../Scene/Scene.h"

class World;

//�Q�[����
class GameSelect : public Scene
{
public:
	// �R���X�g���N�^    
	GameSelect(const IGameManagerPtr& gameManager);

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
};

#endif