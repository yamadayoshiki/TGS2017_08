#include "GamePlayClose.h"
#include "../GamePlay.h"
#include "../../../WorldContains/World/World.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include "../../../CharacterContains/PlayerContains/Player/Player_Parameter.h"
#include "../../../CharacterContains/NeutralContains/Respawn_Effect/Respawn.h"
#include "../../../TextureContains/Texture/Texture.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../../Define/Def_Nagano.h"
#include "../../../DrawManager/DrawOrder.h"
#include "../../Elements/ZoomSprite/ZoomSprite.h"

#include <GStype.h>
GamePlayClose::GamePlayClose()
	: m_CurState(State::Stop)
	, p_Respown(nullptr)
	, p_BlackScreen(nullptr) {
	m_SpriteMap.clear();
}

void GamePlayClose::OnStart() {
	//world‚É’Ç‰Á‚¹‚¸
	m_SpriteMap[State::Stop] = std::make_shared<ZoomSprite>(p_World.get(), SCREEN_SIZE / 2, p_GameManager, std::make_shared<Texture>("Sokomade", p_GameManager->GetDrawManager(), DrawOrder::UI_Front3));
	m_SpriteMap[State::Clear] = std::make_shared<ZoomSprite>(p_World.get(), SCREEN_SIZE / 2, p_GameManager, std::make_shared<Texture>("StageClear", p_GameManager->GetDrawManager(), DrawOrder::UI_Front3));
	for (auto itr = m_SpriteMap.begin(); itr != m_SpriteMap.end(); itr++)
		itr->second->ChangeDisplayMode(DisplayMode::NonDisplay);

	ChangeState(State::Stop);

	p_Parent.lock()->StopWorld();

	p_Respown = std::make_unique<Respawn>(p_World.get(), p_GameManager->GetPlayerParameter().getPosition(), p_GameManager, DrawOrder::UI_Front3);
	p_BlackScreen = std::make_unique<Texture>("black_screen", p_GameManager->GetDrawManager(), DrawOrder::UI_Front1);
	p_BlackScreen->GetParameter()->m_Position = SCREEN_SIZE / 2;
	p_BlackScreen->GetParameter()->m_Color = GScolor(1.0f, 1.0f, 1.0f, 0.8f);

	p_Respown->initialize();
	p_Respown->getTexture()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_World->findActor(ActorName::Player)->getTexture()->ChangeDrawOredr(DrawOrder::UI_Front2);
}

void GamePlayClose::OnUpdate(float deltaTime) {
	if (m_CurState == State::End) {
		p_World->findActor(ActorName::Player)->getTexture()->ChangeDisplayMode(DisplayMode::NonDisplay);
		p_Respown->update(0.1f);
		p_Respown->LateUpdate();

		if (p_Respown->GetDead())
		{
			p_Respown->dead();
			p_World->EndRequest(SceneName::GameResult);
		}
		return;
	}
	m_SpriteMap[m_CurState]->update(deltaTime);
	m_SpriteMap[m_CurState]->LateUpdate();

	if (m_SpriteMap[m_CurState]->IsEnd() == true)
		ChangeState((State)(((int)m_CurState) + 1));

}

void GamePlayClose::OnDraw() const {
}

void GamePlayClose::OnEnd() {
	p_BlackScreen->ChangeDisplayMode(DisplayMode::NonDisplay);
}

void GamePlayClose::ChangeState(const State next) {
	if (m_CurState != State::End)
		m_SpriteMap[m_CurState]->dead();

	m_CurState = next;
	if (m_CurState != State::End)
		m_SpriteMap[m_CurState]->ChangeDisplayMode(DisplayMode::Display);
	else
		p_Respown->getTexture()->ChangeDisplayMode(DisplayMode::Display);
}
