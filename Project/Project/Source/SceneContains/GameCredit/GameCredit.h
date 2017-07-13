#ifndef GAMECREDIT_H_
#define GAMECREDIT_H_

#include "../Scene/Scene.h"
#include"../SceneManager/SceneManager.h"

class World;

//�Q�[����
class GameCredit : public Scene
{
public:
	// �R���X�g���N�^    
	GameCredit(const IGameManagerPtr& gameManager);

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	//�`��
	virtual void OnDraw()const;
	//�I��
	virtual void End();

private:
	SceneManager*	m_SceneManager;
};

#endif