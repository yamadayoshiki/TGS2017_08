#include "ResultStaging.h"

#include "../../../WorldContains/World/World.h"
#include"../../../ActorContains/ActorGroup.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../Utility/Sound/SoundName.h"
#include"../../../CharacterContains/NeutralContains/Smork_Effect/Smork_Effect.h"
#include"../BigBlock.h"


ResultStaging::ResultStaging(IWorld* world, const IGameManagerPtr & gameManager)
	:p_World(world),p_GameManager(gameManager),
	m_Transition(std::make_shared<BigBlock>(gameManager))
{
}

// �J�n     
void ResultStaging::Start()
{
	is_End = false;
	//�u���b�N�̔j�󉉏o�̊J�n
	m_Transition->start();
}
// �X�V     
void ResultStaging::Update(float deltaTime)
{
	if ((int)timer_  % 4 == 0) {
		float x = gsRandf(550, 1150);
		float y = gsRandf(300, 800);
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
void ResultStaging::Draw()const
{
	//�u���b�N�̔j�󉉏o�̕`��
	m_Transition->draw();
}
//�I��
void ResultStaging::End()
{

}

// �I�����Ă��邩�H     
bool ResultStaging::IsEnd() const
{
	return is_End;
}

SceneName ResultStaging::Next() const {
	return SceneName::ResultEnd;
}
void ResultStaging::SetName(const SceneName & name) {

}

SceneName ResultStaging::GetName() {
	return SceneName::ResultStaging;
}