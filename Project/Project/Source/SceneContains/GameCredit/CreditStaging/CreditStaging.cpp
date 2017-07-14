#include "CreditStaging.h"

#include "../../../WorldContains/World/World.h"
#include"../../../ActorContains/ActorGroup.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../Utility/Sound/SoundName.h"
#include"../../../CharacterContains/NeutralContains/Smork_Effect/Smork_Effect.h"
#include"../BigBlock2.h"


CreditStaging::CreditStaging(IWorld* world, const IGameManagerPtr & gameManager)
	:p_World(world), p_GameManager(gameManager),
	m_Transition(std::make_shared<BigBlock2>(gameManager))
{
}

// �J�n     
void CreditStaging::Start()
{
	is_End = false;
	//�u���b�N�̔j�󉉏o�̊J�n
	m_Transition->start();
}
// �X�V     
void CreditStaging::Update(float deltaTime)
{
	if ((int)timer_ % 4 == 0) {
		float x = gsRandf(550, 1150);
		float y = gsRandf(100, 800);
		GSvector2 pos = GSvector2(x, y);
		p_World->addActor(ActorGroup::Effect, std::make_shared<Smork_Effect>(p_World.get(), pos, p_GameManager));
		timer_ = 0.0f;
	}

	//�u���b�N�̔j�󉉏o�̍X�V
	m_Transition->update(deltaTime);

	timer_ += deltaTime;

	if (m_Transition->isEnd()) {
		is_End = true;
	}
}
//�`��
void CreditStaging::Draw()const
{
	//�u���b�N�̔j�󉉏o�̕`��
	m_Transition->draw();
}
//�I��
void CreditStaging::End()
{

}

// �I�����Ă��邩�H     
bool CreditStaging::IsEnd() const
{
	return is_End;
}

SceneName CreditStaging::Next() const {
	return SceneName::ResultEnd;
}
void CreditStaging::SetName(const SceneName & name) {

}

SceneName CreditStaging::GetName() {
	return SceneName::ResultStaging;
}