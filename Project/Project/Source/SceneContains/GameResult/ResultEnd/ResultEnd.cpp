#include"ResultEnd.h"
#include<GSmusic.h>

#include"../GameResult.h"
#include "../../../WorldContains/World/World.h"
#include"../../../ActorContains/ActorGroup.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../Utility/Sound/SoundName.h"
#include"../../../Utility/Score/Score.h"
#include"../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include"../../../UIContains/UIManager/UIManager.h"
#include"../../../UIContains/Sprite/Sprite.h"
#include"../../../UIContains/Number/Number.h"
#include"../../../UIContains/Rank/Rank.h"
#include"../../../TextureContains/Texture/Texture.h"


ResultEnd::ResultEnd() {
}

// �J�n     
void ResultEnd::OnStart()
{
	timer_ = 0.0f;

}
// �X�V     
void ResultEnd::OnUpdate(float deltaTime)
{
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetPratform().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetScoreUI().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetScoreUI().lock()->SetNum(p_GameManager->GetScore()->ReleaseScore());
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetRankUI().lock()->ChangeDisplayMode(DisplayMode::Display);
	//float t = timer_ / maxTimer_;
	//GScolor color = m_Color.lerp(GScolor(1.0f, 1.0f, 1.0f, 0.0f), t);
	//p_Texture->GetParameter()->m_Color = color;

	//p_Transition->update(deltaTime);

	if (timer_ >= 60 * 5)
	{
		//���̃X�e�[�W���Ȃ��ꍇ�Q�[���N���A�֑J��
		if (MapOrder == 11) {
			p_World->EndRequest(SceneName::GameCredit);
			return;
		}
		MapOrder += 1;
		p_GameManager->set_MapOrder(MapOrder);
		gsStopMusic();
		p_World->EndRequest(SceneName::GamePlay);
	}
	timer_ += deltaTime;
}
//�`��
void ResultEnd::OnDraw()const {
}

//�I��
void ResultEnd::OnEnd() {
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetPratform().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetScoreUI().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetRankUI().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);

}
