#include"GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../Utility/InputState/InputState.h"
#include"../../../Utility/EnumRap/EnumRap.h"

#include<GSmusic.h>

//コンストラクタ
GameManager::GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState)
	:p_Renderer2D(renderer2D), p_InputState(inputState), p_SceneEnum(std::make_shared<EnumRap<SceneName>>()){
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

	//UI

	//Title
	p_Renderer2D->LoadTexture("Title", "Resource/Texture/UI/Title/title.png");
	p_Renderer2D->LoadTexture("WideHead", "Resource/Texture/UI/Title/WideHead.png");
	p_Renderer2D->LoadTexture("Start", "Resource/Texture/UI/Title/Start.png");
	p_Renderer2D->LoadTexture("logo", "Resource/Texture/UI/Title/logo.png");

	//Play

	//Clear
	p_Renderer2D->LoadTexture("Clear", "Resource/Texture/UI/Result_Clear.png");
	p_Renderer2D->LoadTexture("GameClear", "Resource/Texture/UI/Clear/GameClear.png");
	
	//Over
	p_Renderer2D->LoadTexture("Over", "Resource/Texture/UI/Over/Over.png");
	p_Renderer2D->LoadTexture("Restart", "Resource/Texture/UI/Over/Restart.png");

	//Pause
	p_Renderer2D->LoadTexture("Pause", "Resource/Texture/UI/Pause/Poze.png");
	p_Renderer2D->LoadTexture("PauseRG", "Resource/Texture/UI/Pause/ReturnGame.png");
	p_Renderer2D->LoadTexture("PauseRT", "Resource/Texture/UI/Pause/ReturnTitle.png");

	//Result
	p_Renderer2D->LoadTexture("RankS", "Resource/Texture/UI/Result/S.png");
	p_Renderer2D->LoadTexture("RankA", "Resource/Texture/UI/Result/A.png");
	p_Renderer2D->LoadTexture("RankB", "Resource/Texture/UI/Result/B.png");
	p_Renderer2D->LoadTexture("RankC", "Resource/Texture/UI/Result/C.png");
	p_Renderer2D->LoadTexture("NextStage", "Resource/Texture/UI/Result/NextStage.png");
	p_Renderer2D->LoadTexture("ReturnTitle", "Resource/Texture/UI/Result/ReturnTitle.png");
	p_Renderer2D->LoadTexture("OverReturnTitle", "Resource/Texture/UI/Over/ReturnTitle.png");


	p_Renderer2D->LoadTexture("Black", "Resource/Texture/UI/black_screen.png");
	p_Renderer2D->LoadTexture("Cursor", "Resource/Texture/UI/Play/DeadCursor.png");
	p_Renderer2D->LoadTexture("Return", "Resource/Texture/UI/return.png");
	p_Renderer2D->LoadTexture("Next", "Resource/Texture/UI/next.png");
	p_Renderer2D->LoadTexture("carsor", "Resource/Texture/UI/carsor.png");

	//gsLoadMusic(1,"Resource/SE/")
	gsLoadMusic(0, "Resource/BGM/title.mp3", GMIDIFLAG::GMIDI_LOOP);
	gsLoadMusic(1, "Resource/BGM/play1.mp3", GMIDIFLAG::GMIDI_LOOP);
	gsLoadMusic(2, "Resoure/BGM/stageclear",GMIDIFLAG::GMIDI_LOOP);
	gsLoadMusic(3, "Resoure/BGM/over", GMIDIFLAG::GMIDI_LOOP);
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

void GameManager::set_MapOrder(int MapOrder)
{
	MapOrder_ = MapOrder;
}

int GameManager::get_MapOrder() const
{
	return MapOrder_;
}

//終了処理
void GameManager::Finalize() {
	p_Renderer2D->Initialize();
}