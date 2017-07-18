#include "Guide.h"
#include <GSvector2.h>
#include "../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../../TextureContains/Texture/Texture.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include "../../../WorldContains/EventMessage/EventMessage.h"

Guide::Guide(IWorld * world, const IGameManagerPtr & gameManager)
	: Actor(
		world,
		ActorName::UI_Sprite,
		GSvector2(0.0f, 0.0f),
		gameManager)
	, m_CurState(State::Tutorial1)
	, m_Timer(0) {
	p_RightBG = std::make_unique<Texture>("TutorialRightBG", gameManager->GetDrawManager(), DrawOrder::UI);
	p_Button = std::make_unique<AnimationTexture>("TutorialRightBButton", gameManager->GetDrawManager(), DrawOrder::UI_Front1, 64, 30);
	p_Motion = std::make_unique<AnimationTexture>("TutorialRightInsert", gameManager->GetDrawManager(), DrawOrder::UI_Front1, 64, 30);
	p_LeftItem = std::make_unique<Texture>("TutorialLeft1", gameManager->GetDrawManager(), DrawOrder::UI);
}

Guide::~Guide() {
}

void Guide::onUpdate(float deltaTime) {
	p_RightBG->Update(deltaTime);
	p_Button->Update(deltaTime);
	p_Motion->Update(deltaTime);
	p_LeftItem->Update(deltaTime);

	switch (m_CurState){
	case State::Tutorial4:
		m_Timer++;
		if (m_Timer > 120)
			Change(State::Tutorial5);
		break;
	}
}

void Guide::onMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::PLAYER_ROUNDS:
		if (m_CurState == State::Tutorial1)
			Change(State::Tutorial2);
		break;

	case EventMessage::PLAYER_CRUSH:
		if (m_CurState == State::Tutorial2)
			Change(State::Tutorial3);
		break;
	}
}

void Guide::Change(const State next) {
	if (m_CurState == next) return;
	m_CurState = next;
	switch (next)
	{
	case State::Tutorial2:
		p_Button = std::make_unique<AnimationTexture>("TutorialRightYButton", p_GameManager->GetDrawManager(), DrawOrder::UI_Front1, 64, 30);
		p_Motion = std::make_unique<AnimationTexture>("TutorialRightBlockCrush", p_GameManager->GetDrawManager(), DrawOrder::UI_Front1, 64, 30);
		p_LeftItem->ChangeTexture("TutorialLeft2", DrawOrder::UI);
		break;

	case State::Tutorial3:
		p_Motion = std::make_unique<AnimationTexture>("TutorialRightEnemyCrush", p_GameManager->GetDrawManager(), DrawOrder::UI_Front1, 64, 30);
		p_LeftItem->ChangeTexture("TutorialLeft3", DrawOrder::UI);
		break;

	case State::Tutorial4:
		p_Button->ChangeDisplayMode(DisplayMode::NonDisplay);
		p_Motion->ChangeDisplayMode(DisplayMode::NonDisplay);
		p_LeftItem->ChangeTexture("TutorialLeft4", DrawOrder::UI);
		break;

	case State::Tutorial5:
		p_Button = std::make_unique<AnimationTexture>("TutorialRightAButton", p_GameManager->GetDrawManager(), DrawOrder::UI_Front1, 64, 30);
		p_Motion = std::make_unique<AnimationTexture>("TutorialRightDash", p_GameManager->GetDrawManager(), DrawOrder::UI_Front1, 64, 30);
		p_LeftItem->ChangeTexture("TutorialLeft5", DrawOrder::UI);
		break;

	case State::Tutorial6:
		p_Button = std::make_unique<AnimationTexture>("TutorialRightButtonCharge", p_GameManager->GetDrawManager(), DrawOrder::UI_Front1, 64, 30);
		p_Motion = std::make_unique<AnimationTexture>("TutorialRightCharge", p_GameManager->GetDrawManager(), DrawOrder::UI_Front1, 64, 30);
		p_LeftItem->ChangeTexture("TutorialLeft6", DrawOrder::UI);
		break;

	case State::Tutorial7:
		p_Button = std::make_unique<AnimationTexture>("TutorialRightButtonChargeCrush", p_GameManager->GetDrawManager(), DrawOrder::UI_Front1, 64, 30);
		p_Motion = std::make_unique<AnimationTexture>("TutorialRightChargeCrush", p_GameManager->GetDrawManager(), DrawOrder::UI_Front1, 64, 30);
		p_LeftItem->ChangeTexture("TutorialLeft7", DrawOrder::UI);
		break;

	case State::Tutorial8:
		p_Button->ChangeDisplayMode(DisplayMode::NonDisplay);
		p_Motion->ChangeDisplayMode(DisplayMode::NonDisplay);
		p_LeftItem->ChangeTexture("TutorialLeft8", DrawOrder::UI);
		break;
	}
}
