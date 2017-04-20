#include"GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../Utility/InputState/InputState.h"

//コンストラクタ
GameManager::GameManager(Renderer2D* renderer2D,InputState* inputState)
	:p_Renderer2D(renderer2D),p_InputState(inputState) {
}

//コンテンツの読み込み
void GameManager::LoadContent() {
	p_Renderer2D->LoadTexture("Player", "Resource/white.png");
}

//コンテンツの削除
void GameManager::UnLoadContent() {
}

//更新処理
void GameManager::Update(){
	p_InputState->Update();
}

//レンダラーの取得
Renderer2D* GameManager::GetRenderer2D() {
	return p_Renderer2D;
}

//インプットステイトの取得
InputState* GameManager::GetInputState() {
	return p_InputState;
}

//終了処理
void GameManager::Finalize() {
	delete p_Renderer2D;
	delete p_InputState;
}