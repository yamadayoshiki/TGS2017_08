#ifndef GAMERESULT_H_
#define GAMERESULT_H_

#include "../Scene/Scene.h"
#include"../SceneManager/SceneManager.h"

#include <string>

#include<gslib.h>
class World;

//�Q�[����
class GameResult : public Scene
{
public:
	// �R���X�g���N�^    
	GameResult(const IGameManagerPtr& gameManager);

	enum class Rank{
		RankS,
		RankA,
		RankB,
		RankC,
	};
protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	//�`��
	virtual void OnDraw()const;
	//�I��
	virtual void OnEnd();

private:
	SceneManager*	m_SceneManager;

	float timer_{ 0.0f };
	
};

#endif