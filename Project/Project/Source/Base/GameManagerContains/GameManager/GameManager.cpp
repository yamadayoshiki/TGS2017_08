#include"GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../Utility/InputState/InputState.h"
#include"../../../Utility/EnumRap/EnumRap.h"
#include"../../../Utility/SE_Name.h"

#include<GSmusic.h>

//�R���X�g���N�^
GameManager::GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState)
	:p_Renderer2D(renderer2D), p_InputState(inputState), p_SceneEnum(std::make_shared<EnumRap<SceneName>>()){
	m_Parameter.m_Remaining = 3;
}

//�R���e���c�̓ǂݍ���
void GameManager::LoadContent() {
	p_Renderer2D->LoadTexture("Player_Close", "Resource/Texture/Player/jiki_close.png");
	p_Renderer2D->LoadTexture("Player_Open", "Resource/Texture/Player/jiki_anime7.png");
	p_Renderer2D->LoadTexture("Player_Clip", "Resource/Texture/Player/jiki_clip.png");
	p_Renderer2D->LoadTexture("Player_O_Animation", "Resource/Texture/Player/jiki_anime.png");
	p_Renderer2D->LoadTexture("Player_C_Animation1", "Resource/Texture/Player/jiki_anime2.png");
	p_Renderer2D->LoadTexture("Player_C_Animation2", "Resource/Texture/Player/jiki_anime3.png");
	p_Renderer2D->LoadTexture("Player_Invincile", "Resource/Texture/Player/jiki_anime4.png");
	p_Renderer2D->LoadTexture("Player_O_Animation2", "Resource/Texture/Player/jiki_anime5.png");
	p_Renderer2D->LoadTexture("Player_C_Animation3", "Resource/Texture/Player/jiki_anime6.png");
	p_Renderer2D->LoadTexture("Player_Open2", "Resource/Texture/Player/PlayerOpen2.png");

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

	gsLoadSE(SE_PLAYER_ARM, "Resource/Sound/SE/Player/Arm.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_CRUSH, "Resource/Sound/SE/Player/Crush.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_CRUSH_AFTER, "Resource/Sound/SE/Player/Crush_After.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_DASH, "Resource/Sound/SE/Player/Dash.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_PLAY, "Resource/Sound/SE/Player/play.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_EXPLOSION, "Resource/Sound/SE/Player/Player_Explosion.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_RESPAWN, "Resource/Sound/SE/Player/Respawn.wav", 1, GWAVE_DEFAULT);

	gsLoadSE(SE_ENEMY_CHILDAPPEARED, "Resource/Sound/SE/Enemy/ChildAppeared.mp3", 10, GWAVE_DEFAULT);
	gsLoadSE(SE_ENEMY_ENEMYEXPLOTION, "Resource/Sound/SE/Enemy/EnemyExplotion.mp3", 10, GWAVE_DEFAULT);
	gsLoadSE(SE_ENEMY_GENERATESINGING, "Resource/Sound/SE/Enemy/GenerateSinging.mp3", 10, GWAVE_DEFAULT);
	gsLoadSE(SE_ENEMY_RUSH, "Resource/Sound/SE/Enemy/Rush.mp3", 10, GWAVE_DEFAULT);
	gsLoadSE(SE_ENEMY_SHOT, "Resource/Sound/SE/Enemy/Shot.mp3", 10, GWAVE_DEFAULT);
	gsLoadSE(SE_ENEMY_SPINBOUND, "Resource/Sound/SE/Enemy/SpinBound.mp3", 10, GWAVE_DEFAULT);
}

//�R���e���c�̍폜
void GameManager::UnLoadContent() {
	p_Renderer2D->Initialize();
}

//�X�V����
void GameManager::Update() {
	//���͏����X�V
	p_InputState->Update();
}

//�����_���[�̎擾
Renderer2DPtr GameManager::GetRenderer2D() {
	return p_Renderer2D;
}

//�C���v�b�g�X�e�C�g�̎擾
InputStatePtr GameManager::GetInputState() {
	return p_InputState;
}

//�V�[����Enum�̎擾
EnumRapPtr<SceneName> GameManager::GetSceneEnum(){
	return p_SceneEnum;
}

//�v���C���[�p�����[�^�[�̎擾
Player_Parameter& GameManager::GetPlayerParameter()
{
	return m_Parameter;
}
//�v���C���[�p�����[�^�[�̐ݒ�				
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

//�I������
void GameManager::Finalize() {
	p_Renderer2D->Initialize();
}