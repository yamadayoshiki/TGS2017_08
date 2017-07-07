#include"GameManager.h"
#include "../../../DrawOrderManager/DrawOrderManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../Utility/InputState/InputState.h"
#include"../../../Utility/Score/Score.h"
#include"../../../Utility/EnumRap/EnumRap.h"
#include"../../../Utility/Sound/Sound.h"
#include"../../../Utility/Sound/SoundName.h"

#include<GSmusic.h>

//コンストラクタ
GameManager::GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState, const ScorePtr& score)
	:p_Renderer2D(renderer2D), p_InputState(inputState), p_Score(score), p_SceneEnum(std::make_shared<EnumRap<SceneName>>()) {
	m_Parameter.m_Remaining = 3;
	p_DrawOrderManager = std::make_shared<DrawOrderManager>(p_Renderer2D);
}


//コンテンツの読み込み
void GameManager::LoadContent() {
	//PlayerTexture
	p_Renderer2D->LoadTexture("Player_Close", "Resource/Texture/Player/jiki_anime8.png");
	p_Renderer2D->LoadTexture("Player_Open", "Resource/Texture/Player/jiki_anime7.png");
	p_Renderer2D->LoadTexture("Player_Clip", "Resource/Texture/Player/jiki_anime9.png");
	p_Renderer2D->LoadTexture("Player_Invincble", "Resource/Texture/Player/jiki_anime.png");
	p_Renderer2D->LoadTexture("Player_AfterImage", "Resource/Texture/Player/jiki_zanzou.png");

	//EnemyTexture
	p_Renderer2D->LoadTexture("Enemy01", "Resource/Texture/Enemys/Enemy01.png");
	p_Renderer2D->LoadTexture("Enemy02", "Resource/Texture/Enemys/Enemy02.png");
	p_Renderer2D->LoadTexture("Enemy03", "Resource/Texture/Enemys/Enemy03.png");
	p_Renderer2D->LoadTexture("Enemy04", "Resource/Texture/Enemys/Enemy04.png");
	p_Renderer2D->LoadTexture("Enemy06", "Resource/Texture/Enemys/Enemy06.png");
	p_Renderer2D->LoadTexture("Enemy07Attack", "Resource/Texture/Enemys/Enemy07Attack.png");
	p_Renderer2D->LoadTexture("Enemy07Normal", "Resource/Texture/Enemys/Enemy07Normal.png");
	p_Renderer2D->LoadTexture("Enemy08Attack", "Resource/Texture/Enemys/Enemy08Attack.png");
	p_Renderer2D->LoadTexture("Enemy08Normal", "Resource/Texture/Enemys/Enemy08Normal.png");
	p_Renderer2D->LoadTexture("Enemy09", "Resource/Texture/Enemys/Enemy09.png");
	p_Renderer2D->LoadTexture("Enemy10", "Resource/Texture/Enemys/Enemy10.png");
	p_Renderer2D->LoadTexture("EnemyBullet01", "Resource/Texture/Enemys/EnemyBullet01.png");

	//Block
	p_Renderer2D->LoadTexture("Block5", "Resource/Texture/UI/Breakwall.png");

	//EffectTexture
	p_Renderer2D->LoadTexture("Explosion", "Resource/Texture/Effect/Explosion.png");
	p_Renderer2D->LoadTexture("Charge0", "Resource/Texture/Effect/Charge_Effect0.png");
	p_Renderer2D->LoadTexture("Charge1", "Resource/Texture/Effect/charge.png");
	p_Renderer2D->LoadTexture("Charge2", "Resource/Texture/Effect/charge4.png");
	p_Renderer2D->LoadTexture("Charge3", "Resource/Texture/Effect/charge5.png");
	p_Renderer2D->LoadTexture("Crush", "Resource/Texture/Effect/Crush.png");
	p_Renderer2D->LoadTexture("Repel", "Resource/Texture/Effect/hajiki.png");
	p_Renderer2D->LoadTexture("Respawn", "Resource/Texture/Effect/respawn.png");
	p_Renderer2D->LoadTexture("Smork", "Resource/Texture/Effect/syutugenn.png");

	//UI

	//Title
	p_Renderer2D->LoadTexture("Title", "Resource/Texture/UI/Title/title.png");
	p_Renderer2D->LoadTexture("WideHead", "Resource/Texture/UI/Title/titleblock3.png");
	p_Renderer2D->LoadTexture("Start", "Resource/Texture/UI/Title/Start.png");
	p_Renderer2D->LoadTexture("logo", "Resource/Texture/UI/Title/logo.png");

	//Play
	p_Renderer2D->LoadTexture("game_back", "Resource/Texture/UI/Play/play.png");
	p_Renderer2D->LoadTexture("combo_font", "Resource/Texture/UI/Play/combo_font.png");
	p_Renderer2D->LoadTexture("score_font", "Resource/Texture/UI/Play/score_font.png");
	p_Renderer2D->LoadTexture("gauge_back", "Resource/Texture/UI/Play/geji.png");
	p_Renderer2D->LoadTexture("gauge_front", "Resource/Texture/UI/Play/geji2.png");
	p_Renderer2D->LoadTexture("life", "Resource/Texture/UI/Play/life.png");
	p_Renderer2D->LoadTexture("batu", "Resource/Texture/UI/Play/batu.png");

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
	p_Renderer2D->LoadTexture("RankS", "Resource/Texture/UI/Result/RankS.png");
	p_Renderer2D->LoadTexture("RankA", "Resource/Texture/UI/Result/RankA.png");
	p_Renderer2D->LoadTexture("RankB", "Resource/Texture/UI/Result/RankB.png");
	p_Renderer2D->LoadTexture("RankC", "Resource/Texture/UI/Result/RankC.png");
	
	p_Renderer2D->LoadTexture("BigBlock", "Resource/Texture/UI/Result/bigblock.png");
	p_Renderer2D->LoadTexture("BlockBreak", "Resource/Texture/UI/Result/blockbreak2.png");
	p_Renderer2D->LoadTexture("Platform", "Resource/Texture/UI/Result/base.png");


	//p_Renderer2D->LoadTexture("Black", "Resource/Texture/UI/black_screen.png");
	//p_Renderer2D->LoadTexture("Cursor", "Resource/Texture/UI/Play/DeadCursor.png");
	//p_Renderer2D->LoadTexture("Return", "Resource/Texture/UI/return.png");
	//p_Renderer2D->LoadTexture("Next", "Resource/Texture/UI/next.png");
	//p_Renderer2D->LoadTexture("carsor", "Resource/Texture/UI/carsor.png");

	//gsLoadMusic(1,"Resource/SE/")
	gsLoadMusic(BGM_GAME_TITLE, "Resource/Sound/BGM/title.mp3", GMIDIFLAG::GMIDI_LOOP);
	gsLoadMusic(BGM_GAME_PLAY, "Resource/Sound/BGM/play.mp3", GMIDIFLAG::GMIDI_LOOP);
	gsLoadMusic(BGM_GAME_CLER, "Resource/Sound/BGM/stageclear.mp3", GMIDIFLAG::GMIDI_LOOP);
	gsLoadMusic(BGM_GAME_OVER, "Resource/Sound/BGM/over.mp3", GMIDIFLAG::GMIDI_LOOP);

	//PlayerSE
	gsLoadSE(SE_PLAYER_ARM, "Resource/Sound/SE/Player/Arm.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_CLIP, "Resource/Sound/SE/Player/clip.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_CRUSH, "Resource/Sound/SE/Player/Crush.wav", 4, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_CRUSH_AFTER, "Resource/Sound/SE/Player/Crush_After.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_DASH, "Resource/Sound/SE/Player/Dash.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_PLAY, "Resource/Sound/SE/Player/play.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_EXPLOSION, "Resource/Sound/SE/Player/Player_Explosion.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_RESPAWN, "Resource/Sound/SE/Player/Respawn.wav", 1, GWAVE_DEFAULT);

	//EnemySE
	gsLoadSE(SE_ENEMY_CHILDAPPEARED, "Resource/Sound/SE/Enemy/ChildAppeared.mp3", 10, GWAVE_DEFAULT);
	gsLoadSE(SE_ENEMY_ENEMYEXPLOTION, "Resource/Sound/SE/Enemy/EnemyExplotion.mp3", 10, GWAVE_DEFAULT);
	gsLoadSE(SE_ENEMY_GENERATESINGING, "Resource/Sound/SE/Enemy/GenerateSinging.mp3", 10, GWAVE_DEFAULT);
	gsLoadSE(SE_ENEMY_RUSH, "Resource/Sound/SE/Enemy/Rush.mp3", 10, GWAVE_DEFAULT);
	gsLoadSE(SE_ENEMY_SHOT, "Resource/Sound/SE/Enemy/Shot.mp3", 10, GWAVE_DEFAULT);
	gsLoadSE(SE_ENEMY_SPINBOUND, "Resource/Sound/SE/Enemy/SpinBound.mp3", 10, GWAVE_DEFAULT);
	
	//UISE
	gsLoadSE(SE_BACK, "Resource/Sound/SE/Scene/back.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_DECITION, "Resource/Sound/SE/Scene/decition.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_KOMBOUP, "Resource/Sound/SE/Scene/konboup.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PAUSE_CLOSE, "Resource/Sound/SE/Scene/pauseclose.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PAUSE_OPEN, "Resource/Sound/SE/Scene/pauseopen.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_SHOWINGSCORE, "Resource/Sound/SE/Scene/showingscore.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_SHOWINGSCORE_BEFORE, "Resource/Sound/SE/Scene/showingscorebefore.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_START, "Resource/Sound/SE/Scene/start.wav", 1, GWAVE_DEFAULT);

	//TutorialSE
	gsLoadSE(SE_GAID, "Resource/Sound/SE/Scene/Tutorial/gaidoSE.wav", 1, GWAVE_DEFAULT);
	//TitleSE
	gsLoadSE(SE_START, "Resource/Sound/SE/Scene/Title/titledown.wav", 1, GWAVE_DEFAULT);
	//PlaySE
	gsLoadSE(SE_WHISTL, "Resource/Sound/SE/Scene/Play/hoissuru.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAY_FONT, "Resource/Sound/SE/Scene/Play/playfontse.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_STAGE_CLER, "Resource/Sound/SE/Scene/Play/stagecleaSE.wav", 1, GWAVE_DEFAULT);
	//ResultSE
	gsLoadSE(SE_S, "Resource/Sound/SE/Scene/Result/S.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_A, "Resource/Sound/SE/Scene/Result/A.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_B, "Resource/Sound/SE/Scene/Result/B.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_C, "Resource/Sound/SE/Scene/Result/C.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_BLOCK_BREAK, "Resource/Sound/SE/Scene/Result/blockbreak.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_SCORE_ROLE, "Resource/Sound/SE/Scene/Result/scorerole.wav", 1, GWAVE_DEFAULT);

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

//描画管理の取得
DrawOrderManagerSPtr GameManager::GetDrawOrderManagerPtr() {
	return p_DrawOrderManager;
}

//インプットステイトの取得
InputStatePtr GameManager::GetInputState() {
	return p_InputState;
}

//シーンのEnumの取得
EnumRapPtr<SceneName> GameManager::GetSceneEnum() {
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
ScorePtr GameManager::GetScore() {
	return p_Score;
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
	p_Renderer2D->UnLoadTexture();

	gsDeleteMusic(BGM_GAME_TITLE);
	gsDeleteMusic(BGM_GAME_PLAY);
	gsDeleteMusic(BGM_GAME_CLER);
	gsDeleteMusic(BGM_GAME_OVER);
	gsDeleteSE(SE_PLAYER_ARM);
	gsDeleteSE(SE_PLAYER_CLIP);
	gsDeleteSE(SE_PLAYER_CRUSH);
	gsDeleteSE(SE_PLAYER_CRUSH_AFTER);
	gsDeleteSE(SE_PLAYER_DASH);
	gsDeleteSE(SE_PLAYER_PLAY);
	gsDeleteSE(SE_PLAYER_EXPLOSION);
	gsDeleteSE(SE_PLAYER_RESPAWN);
	gsDeleteSE(SE_ENEMY_CHILDAPPEARED);
	gsDeleteSE(SE_ENEMY_ENEMYEXPLOTION);
	gsDeleteSE(SE_ENEMY_GENERATESINGING);
	gsDeleteSE(SE_ENEMY_RUSH);
	gsDeleteSE(SE_ENEMY_SHOT);
	gsDeleteSE(SE_ENEMY_SPINBOUND);
	gsDeleteSE(SE_BACK);
	gsDeleteSE(SE_DECITION);
	gsDeleteSE(SE_KOMBOUP);
	gsDeleteSE(SE_PAUSE_CLOSE);
	gsDeleteSE(SE_PAUSE_OPEN);
	gsDeleteSE(SE_SHOWINGSCORE);
	gsDeleteSE(SE_SHOWINGSCORE_BEFORE);
	gsDeleteSE(SE_START);
}