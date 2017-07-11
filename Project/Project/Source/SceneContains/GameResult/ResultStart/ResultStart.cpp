#include "ResultStart.h"

#include "../../../WorldContains/World/World.h"
#include"../../../ActorContains/ActorGroup.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../Utility/Sound/SoundName.h"

ResultStart::ResultStart(IWorld* world,const IGameManagerPtr & gameManager)
	:p_World(world),p_GameManager(gameManager)
{
}

// �J�n     
void ResultStart::Start()
{
	is_End = false;
}
// �X�V     
void ResultStart::Update(float deltaTime)
{
	if (timer_ >= 60 * 2)
	{
		is_End = true;
	}

	timer_ += deltaTime;
}
//�`��
void ResultStart::Draw()const
{
	//�傫���u���b�N�̕`��
	p_GameManager->GetRenderer2D()->DrawTexture("BigBlock", GSvector2(550, 300));
}
//�I��
void ResultStart::End()
{

}

// �I�����Ă��邩�H     
bool ResultStart::IsEnd() const
{
	return is_End;
}

SceneName ResultStart::Next() const {
	return SceneName::ResultStaging;
}
void ResultStart::SetName(const SceneName & name) {
	
}

SceneName ResultStart::GetName() {
	return SceneName::ResultStart;
}