#include"GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../Utility/InputState/InputState.h"
#include"../../../Utility/Score/ScorePtr.h"
#include"../../../Utility/EnumRap/EnumRap.h"

//コンストラクタ
GameManager::GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState,const ScorePtr& score)
	:p_Renderer2D(renderer2D), p_InputState(inputState), p_Score(score) ,p_SceneEnum(std::make_shared<EnumRap<SceneName>>()){
	m_Parameter.m_Remaining = 3;
}

//コンテンツの読み込み
void GameManager::LoadContent() {
	p_Renderer2D->LoadTexture("Player_Close", "Resource/Texture/Player/jiki_close.png");
	p_Renderer2D->LoadTexture("Player_Open", "Resource/Texture/Player/jiki_open.png");
	p_Renderer2D->LoadTexture("Player_Clip", "Resource/Texture/Player/jiki_clip.png");
	p_Renderer2D->LoadTexture("Player_O_Animation", "Resource/Texture/Player/jiki_anime.png");
	p_Renderer2D->LoadTexture("Player_C_Animation1", "Resource/Texture/Player/jiki_anime2.png");
	p_Renderer2D->LoadTexture("Player_C_Animation2", "Resource/Texture/Player/jiki_anime3.png");
	p_Renderer2D->LoadTexture("Player_Open2", "Resource/Texture/Player/PlayerOpen2.png");

	p_Renderer2D->LoadTexture("Enemy01", "Resource/Texture/Enemys/Enemy01.png");
	p_Renderer2D->LoadTexture("Enemy02", "Resource/Texture/Enemys/Enemy02.png");
	p_Renderer2D->LoadTexture("Enemy03", "Resource/Texture/Enemys/Enemy03.png");
	p_Renderer2D->LoadTexture("Enemy04", "Resource/Texture/Enemys/Enemy04.png");
	p_Renderer2D->LoadTexture("Block5", "Resource/Texture/UI/Block5.png");
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

//シーンのEnumの取得
EnumRapPtr<SceneName> GameManager::GetSceneEnum(){
	return p_SceneEnum;
}

//プレイヤーパラメーターの取得
Player_Parameter& GameManager::GetPlayerParameter()
{
	return m_Parameter;
}
//プレイヤーパラメーターの設定				
void GameManager::SetPlayerParameter(const Player_Parameter& parameter)
{
	m_Parameter = parameter;
}
//スコアの取得
ScorePtr GameManager::GetScore()
{
	return p_Score;
}

//終了処理
void GameManager::Finalize() {
	p_Renderer2D->Initialize();
}