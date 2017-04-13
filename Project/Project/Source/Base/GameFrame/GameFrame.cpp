#include <GL/GLAux.h>
#include <GL\GL.h>
#include <GL/GLU.h>
#include <gslib.h>

#include"GameFrame.h"

#include "../../WorldContains/World/World.h"
#include "../GameManager/GameManager.h"

//�R���X�g���N�^
GameFrame::GameFrame()
	:Game(1024, 768)
	, p_GameManager(new GameManager())
{
	p_GameManager->LoadContent();
}

//�f�X�g���N�^
GameFrame::~GameFrame()
{
	p_GameManager->UnLoadContent();
}

//������
void GameFrame::start()
{
	p_World = std::make_shared<World>();
}

// �X�V
void GameFrame::update(float time)
{
	p_World->update(time);
}

// �`��
void GameFrame::draw()
{
	p_World->Draw();
}

// �I��
void GameFrame::end()
{
}

// ���s����
bool GameFrame::isRunning()
{
	return GetAsyncKeyState(VK_ESCAPE) == 0;
}