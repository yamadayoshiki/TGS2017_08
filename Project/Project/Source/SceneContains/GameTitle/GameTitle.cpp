#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"
#include "../../UIContains/UIManager/UIManager.h"
#include "../../ActorContains/ActorGroup.h"
#include"../../WorldContains/World/World.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include"../../Utility/Score/Score.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/InputState/InputState.h"
#include"../../Utility/Sound/SoundName.h"
#include"../../Utility/Animation/Animation.h"
#include "../../DrawManager/DrawManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../TextureContains/AnimationTexture/AnimationTexture.h"

#include<GSmusic.h>

// コンストラクタ    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
	m_TitleNum = p_GameManager->GetDrawManager()->RegisterDefaultParam("Title", p_Title, DrawOrder::UI);
	p_Title->m_Center = { 0.0f, 0.0f };
	p_Title->m_Position = { 0.0f,0.0f };
	m_WideHeadNum = p_GameManager->GetDrawManager()->RegisterDefaultParam("WideHead", p_WideHead, DrawOrder::UI);
	p_WideHead->m_Center = { 0.0f,0.0f };
	p_WideHead->m_Position = GSvector2(100, TitleSpeed);
	m_StartNum = p_GameManager->GetDrawManager()->RegisterDefaultParam("Start", p_Start, DrawOrder::UI);
	p_Start->m_Center = { 0.0f,0.0f };
	p_Start->m_Position = GSvector2(400, 700);

	p_GameManager->GetDrawManager()->ChageDisplayMode(m_TitleNum, DisplayMode::NonDisplay);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_WideHeadNum, DisplayMode::NonDisplay);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_StartNum, DisplayMode::NonDisplay);
}

//デストラクタ
GameTitle::~GameTitle(){
	delete p_AnimationTexture;
}
//テクスチャの名前の設定
void GameTitle::setName_TitleAnimation(const std::string & name)
{
	p_AnimationTexture = new AnimationTexture(name, p_GameManager->GetDrawManager(), DrawOrder::UI, 50, 2);
	p_AnimationTexture->Initialize();
	p_AnimationTexture->ChangeDisplayMode(DisplayMode::NonDisplay);
}
//アニメーションのループ回数を取得
unsigned int GameTitle::GetLoopTitleCount()
{
	return p_AnimationTexture->GetLoopCount();
}

// 開始     
void GameTitle::OnStart() {
	p_GameManager->GetPlayerParameter().setRemaining(3);
	p_GameManager->GetScore()->initialze();
	MapOrder = 0;
	p_GameManager->set_MapOrder(MapOrder);

	gsBindMusic(BGM_GAME_TITLE);
	gsPlayMusic();

	p_AnimationTexture = new AnimationTexture("StartLogo", p_GameManager->GetDrawManager(), DrawOrder::UI, 50, 8);
	p_AnimationTexture->GetParameter()->m_Position = GSvector2(450, 700);
	p_AnimationTexture->GetParameter()->m_Center = { 25.0f,25.0f };
	p_AnimationTexture->Initialize();

	p_GameManager->GetDrawManager()->ChageDisplayMode(m_TitleNum, DisplayMode::Display);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_WideHeadNum, DisplayMode::Display);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_StartNum, DisplayMode::Display);
	p_AnimationTexture->ChangeDisplayMode(DisplayMode::Display);
	p_AnimationTexture->Initialize();

}

// 更新
void GameTitle::OnUpdate(float deltaTime) {

	//アニメーションの更新
	p_AnimationTexture->Update(deltaTime);

	//看板の動き
	if (TitleSpeed != 0){
		TitleMove();
	}
	//Bボタンでゲームプレイへ
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) || p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		gsPlaySE(SE_DECITION);
		p_World->EndRequest(SceneName::GamePlay);
	}
}

void GameTitle::OnDraw()const{

}

void GameTitle::OnEnd()
{
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_TitleNum, DisplayMode::NonDisplay);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_WideHeadNum, DisplayMode::NonDisplay);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_StartNum, DisplayMode::NonDisplay);
	p_AnimationTexture->ChangeDisplayMode(DisplayMode::NonDisplay);
	gsStopMusic();
	p_GameManager->set_MapOrder(MapOrder);

}

void GameTitle::TitleMove()
{
	TitleSpeed++;
	TitleSpeed = TitleSpeed + 1;

	if (TitleSpeed == 0)
	{
		TitleSpeed = 0;
	}
}

