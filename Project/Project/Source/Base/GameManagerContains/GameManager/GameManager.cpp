#include"GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../Utility/InputState/InputState.h"
#include"../../../Utility/Score/ScorePtr.h"
#include"../../../Utility/EnumRap/EnumRap.h"
#include"../../../Utility/SE_Name.h"

//�R���X�g���N�^
GameManager::GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState,const ScorePtr& score)
	:p_Renderer2D(renderer2D), p_InputState(inputState), p_Score(score) ,p_SceneEnum(std::make_shared<EnumRap<SceneName>>()){
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

	gsLoadSE(SE_PLAYER_ARM, "Resource/Sound/SE/Player/Arm.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_CRUSH, "Resource/Sound/SE/Player/Crush.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_CRUSH_AFTER, "Resource/Sound/SE/Player/Crush_After.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_DASH, "Resource/Sound/SE/Player/Dash.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_PLAY, "Resource/Sound/SE/Player/play.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_EXPLOSION, "Resource/Sound/SE/Player/Player_Explosion.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(SE_PLAYER_RESPAWN, "Resource/Sound/SE/Player/Respawn.wav", 1, GWAVE_DEFAULT);
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
//�X�R�A�̎擾
ScorePtr GameManager::GetScore()
{
	return p_Score;
}

//�I������
void GameManager::Finalize() {
	p_Renderer2D->Initialize();
}