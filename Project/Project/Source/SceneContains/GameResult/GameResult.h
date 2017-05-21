#ifndef GAMERESULT_H_
#define GAMERESULT_H_

#include "../Scene/Scene.h"
#include <string>
class World;

//�Q�[����
class GameResult : public Scene
{
public:
	// �R���X�g���N�^    
	GameResult(const IGameManagerPtr& gameManager);

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);

private:
	std::string m_Text;
};

#endif