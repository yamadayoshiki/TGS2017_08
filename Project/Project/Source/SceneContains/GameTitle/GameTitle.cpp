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
#include "../Elements/DropSprite/DropSprite.h"
#include "../Elements/StartLogoAnimationFont/StartLogoAnimationFont.h"

#include<GSmusic.h>

// コンストラクタ    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// 開始     
void GameTitle::OnStart() {
	p_GameManager->GetPlayerParameter().setRemaining(3);
	p_GameManager->GetScore()->initialze();
	p_GameManager->set_MapOrder(1);

	//UI生成
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));
	p_World->addActor(ActorGroup::UI, std::make_shared<DropSprite>(p_World.get(), p_GameManager));

	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(315, 700), p_GameManager, "StartLogo1", 60));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(365, 700), p_GameManager, "StartLogo2", 62));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(415, 700), p_GameManager, "StartLogo3", 64));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(465, 700), p_GameManager, "StartLogo4", 66));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(515, 700), p_GameManager, "StartLogo5", 68));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(565, 700), p_GameManager, "StartLogo6", 70));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(615, 700), p_GameManager, "StartLogo7", 72));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(665, 700), p_GameManager, "StartLogo8", 74));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(715, 700), p_GameManager, "StartLogo9", 76));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(765, 700), p_GameManager, "StartLogo10",78));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(815, 700), p_GameManager, "StartLogo11",80));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(865, 700), p_GameManager, "StartLogo12",82));
	p_World->addActor(ActorGroup::UI, std::make_shared<StartLogoAnimationFont>(p_World.get(), GSvector2(915, 700), p_GameManager, "StartLogo13",84));


	gsBindMusic(BGM_GAME_TITLE);
	gsPlayMusic();
}

// 更新
void GameTitle::OnUpdate(float deltaTime) {
	//Bボタンでゲームプレイへ
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) || p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		gsPlaySE(SE_DECITION);
		p_World->EndRequest(SceneName::GameTutorial);
	}
}

void GameTitle::OnDraw()const {
}

void GameTitle::OnEnd() {
	gsStopMusic();
}