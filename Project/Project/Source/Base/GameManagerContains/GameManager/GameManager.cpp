#include"GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../Utility/InputState/InputState.h"

//コンストラクタ
GameManager::GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState)
	:p_Renderer2D(renderer2D), p_InputState(inputState), m_IsEnd(false){
}

//コンテンツの読み込み
void GameManager::LoadContent() {
	p_Renderer2D->LoadTexture("Player", "Resource/white.png");
}

//コンテンツの削除
void GameManager::UnLoadContent() {
	p_Renderer2D->Initialize();
}

//更新処理
void GameManager::Update() {
	//入力処理更新
	p_InputState->Update();
}

//レンダラーの取得
Renderer2DPtr GameManager::GetRenderer2D() {
	return p_Renderer2D;
}

//インプットステイトの取得
InputStatePtr GameManager::GetInputState() {
	return p_InputState;
}

bool GameManager::IsEndScene()
{
	return m_IsEnd;
}

void GameManager::EndScene(bool end){
	m_IsEnd = end;
}

//終了処理
void GameManager::Finalize() {
	p_Renderer2D->Initialize();
}