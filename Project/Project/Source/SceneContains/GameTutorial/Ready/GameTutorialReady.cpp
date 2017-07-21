#include "GameTutorialReady.h"
#include "../../Elements/ZoomSprite/ZoomSprite.h"
#include "../../../Define/Def_Nagano.h"
#include "../../../TextureContains/Texture/Texture.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../WorldContains/World/World.h"
#include "../../../DrawManager/DisplayMode.h"
#include "../GameTutorial.h"
#include "../../Elements/FlashSprite/FlashSprite.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../WorldContains/EventMessage/EventMessage.h"
#include "../../SceneManager/SceneManager.h"
GameTutorialReady::GameTutorialReady()
	: m_CurState(State::End) {
}


void GameTutorialReady::OnStart() {
	//world‚É’Ç‰Á‚¹‚¸
	m_SpriteMap[State::Title] = std::make_shared<ZoomSprite>(p_World.get(), SCREEN_SIZE / 2, p_GameManager, std::make_shared<Texture>("TutorialTitle", p_GameManager->GetDrawManager(), DrawOrder::PauseBack));
	m_SpriteMap[State::Start] = std::make_shared<ZoomSprite>(p_World.get(), SCREEN_SIZE / 2, p_GameManager, std::make_shared<Texture>("PlayStartLogo", p_GameManager->GetDrawManager(), DrawOrder::PauseBack));

	for (auto itr = m_SpriteMap.begin(); itr != m_SpriteMap.end(); itr++)
		itr->second->ChangeDisplayMode(DisplayMode::NonDisplay);

	ChangeState(State::Title);
}

void GameTutorialReady::OnUpdate(float deltaTime) {
	if (m_CurState == State::End) {
		Change(SceneName::Play);
		return;
	}
	p_Parent.lock()->StopWorld();
	m_SpriteMap[m_CurState]->update(deltaTime);
	m_SpriteMap[m_CurState]->LateUpdate();

	if (m_SpriteMap[m_CurState]->IsEnd() == true)
		ChangeState((State)(((int)m_CurState) + 1));

	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_X)) {
		isGameClear = true;
		p_GameManager->GetSceneManager()->HandleMessage(EventMessage::END_SCENE, (void*)SceneName::GamePlay);
		return;
	}
}


void GameTutorialReady::OnEnd() {
	p_Parent.lock()->Restart();
}

void GameTutorialReady::ChangeState(const State next) {
	if (m_CurState != State::End)
		m_SpriteMap[m_CurState]->dead();

	m_CurState = next;
	if (m_CurState != State::End)
		m_SpriteMap[m_CurState]->ChangeDisplayMode(DisplayMode::Display);
}
