#include"CreditStart.h"

#include "../../../WorldContains/World/World.h"
#include"../../../ActorContains/ActorGroup.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../Utility/Sound/SoundName.h"
#include"../../../Utility/Number/NumberTexture.h"
#include"../../../Utility/Score/Score.h"
#include"../../../UIContains/UIManager/UIManager.h"

CreditStart::CreditStart(IWorld* world, const IGameManagerPtr & gameManager)
	:p_World(world), p_GameManager(gameManager)
{
}

// �J�n     
void CreditStart::Start()
{
	is_End = false;
}
// �X�V     
void CreditStart::Update(float deltaTime)
{
	if (timer_ >= 60 * 2)
	{
		is_End = true;
	}

	timer_ += deltaTime;
}
//�`��
void CreditStart::Draw()const
{
	//�傫���u���b�N�̕`��
	p_GameManager->GetRenderer2D()->DrawTexture("BigBlock2", GSvector2(550, 100));
}
//�I��
void CreditStart::End()
{

}

// �I�����Ă��邩�H     
bool CreditStart::IsEnd() const
{
	return is_End;
}

SceneName CreditStart::Next() const {
	return SceneName::ResultStaging;
}
void CreditStart::SetName(const SceneName & name) {

}

SceneName CreditStart::GetName() {
	return SceneName::CreditStart;
}