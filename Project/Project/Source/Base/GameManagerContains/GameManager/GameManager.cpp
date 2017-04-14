#include"GameManager.h"

GameManager::GameManager(Renderer2D* renderer2D)
	:p_Renderer2D(renderer2D)
{
}

void GameManager::LoadContent()
{
}

void GameManager::UnLoadContent()
{
}

Renderer2D* GameManager::GetRenderer2D()
{
	return p_Renderer2D;
}

void GameManager::Finalize()
{
	delete p_Renderer2D;
}