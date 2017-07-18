#include "GameOver.h"
#include <gslib.h>
#include<GSmusic.h>
#include "../SceneName.h"
#include "../../UIContains/UIManager/UIManager.h"
#include "../../ActorContains/ActorGroup.h"
#include "../../WorldContains/World/World.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include"../../Utility/Score/Score.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/InputState/InputState.h"
#include"../../Utility/Sound/SoundName.h"
#include "../../DrawManager/DrawManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"

GameOver::GameOver(const IGameManagerPtr & gameManager)
	:Scene(gameManager) {
}

void GameOver::OnStart() {
	gsBindMusic(BGM_GAME_OVER);
	m_CarsorMovement = CarsorMovement::Left;
	MapOrder = p_GameManager->get_MapOrder();
	p_GameManager->GetPlayerParameter().setRemaining(3);

	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));
}

void GameOver::OnUpdate(float deltaTime) {
	gsPlayMusic();
}

void GameOver::OnDraw() const {
}

void GameOver::OnEnd() {
	gsStopMusic();
}