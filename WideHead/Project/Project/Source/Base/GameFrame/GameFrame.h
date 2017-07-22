#ifndef GAMEFRAME_H_
#define GAMEFRAME_H_

#include<GSgame.h>
#include<memory>

#include "../../SceneContains/SceneManager/SceneManager.h"

class GameManager;

class GameFrame :public gslib::Game
{
public:
	GameFrame();
	~GameFrame();

private:

	// �J�n
	void start() override;
	// �X�V
	void update(float time) override;
	// �`��
	void draw() override;
	// �I��
	void end() override;
	// ���s����
	virtual bool isRunning() override;

private:
	using GameManagerPtr = std::shared_ptr<GameManager>;
	GameManagerPtr p_GameManager;					//�Q�[���}�l�[�W���[
	std::shared_ptr<SceneManager> m_SceneManager;	//�V�[���}�l�[�W���[
};


#endif // !GAMEFRAME_H_