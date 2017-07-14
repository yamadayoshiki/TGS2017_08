#include"ResultEnd.h"
#include<GSmusic.h>

#include "../../../WorldContains/World/World.h"
#include"../../../ActorContains/ActorGroup.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../Utility/Sound/SoundName.h"
#include"../../../Utility/Score/Score.h"
#include"../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include"../../../UIContains/UIManager/UIManager.h"
#include"../../../Utility/Number/NumberTexture.h"
#include"../ResultTransition/ResultTransition.h"
#include"../../../TextureContains/Texture/Texture.h"

ResultEnd::ResultEnd(IWorld* world, const IGameManagerPtr & gameManager)
	:p_World(world),
	p_GameManager(gameManager),
	p_Transition(std::make_shared<ResultTransition>(gameManager)),
	p_Texture(std::make_shared<Texture>("BigBlock", p_GameManager->GetDrawManager(), DrawOrder::BackGround))
{
	//�p�����[�^�̐ݒ�
	p_Texture->GetParameter()->m_Position = GSvector2(550, 300);
	p_Texture->GetParameter()->m_Center = { 0.0f,0.0f };
	p_Texture->GetParameter()->m_Color = m_Color;
}

// �J�n     
void ResultEnd::Start()
{
	// UI�̐���
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, SceneName::GameResult));

	MapOrder = p_GameManager->get_MapOrder();
	is_End = false;
	m_Score = 0;
	p_Transition->start();
}
// �X�V     
void ResultEnd::Update(float deltaTime)
{
	float t = timer_ / maxTimer_;
	GScolor color = m_Color.lerp(GScolor(1.0f, 1.0f, 1.0f, 0.0f), t);
	p_Texture->GetParameter()->m_Color = color;

	p_Transition->update(deltaTime);

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
void ResultEnd::Draw()const
{
	//p_GameManager->GetRenderer2D()->DrawTexture("Platform", GSvector2(625, 450));
	////���U���g�X�R�A�̕`��
	//p_GameManager->GetScore()->setPosition(GSvector2(750, 650));
	//p_GameManager->GetScore()->draw(p_GameManager->GetRenderer2D());

	p_Transition->draw();
}
//�I��
void ResultEnd::End()
{
	gsStopMusic();
}

// �I�����Ă��邩�H     
bool ResultEnd::IsEnd() const
{
	return is_End;
}

SceneName ResultEnd::Next() const {
	return SceneName::GameTitle;
}
void ResultEnd::SetName(const SceneName & name) {

}

SceneName ResultEnd::GetName() {
	return SceneName::ResultEnd;
}