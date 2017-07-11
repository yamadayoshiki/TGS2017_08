#include "CreditEnd.h"

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

CreditEnd::CreditEnd(IWorld* world, const IGameManagerPtr & gameManager)
	:p_World(world), p_GameManager(gameManager)
{
}

// 開始     
void CreditEnd::Start()
{
	p_GameManager->set_MapOrder(0);


	// UIの生成
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, SceneName::GameCredit));

	MapOrder = p_GameManager->get_MapOrder();
	is_End = false;
	m_Score = 0;

	//パラメータの設定
	m_Param.SetPosition(GSvector2(550, 100));
	m_Param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("BigBlock2"));
	m_Param.SetColor(m_Color);
	m_Param.SetScale({ 1.0f,1.0f });
	m_Param.SetCenter({ 0.0f,0.0f });
	m_Param.SetRotate(0.0f);
}
// 更新     
void CreditEnd::Update(float deltaTime)
{
	float t = timer_ / maxTimer_;
	GScolor color = m_Color.lerp(GScolor(1.0f, 1.0f, 1.0f, 0.0f), t);
	m_Param.SetColor(color);

	if (timer_ >= 60 * 5)
	{
		gsStopMusic();
		p_World->EndRequest(SceneName::GameTitle);
	}

	//if (p_GameManager->GetScore()->ReleaseScore() != m_Score && color.a <= 0.0f)
	//{
	//	m_Score += 1;
	//}

	timer_ += deltaTime;
}
//描画
void CreditEnd::Draw()const
{
	static const NumberTexture number(1000, 40, 60);

	p_GameManager->GetRenderer2D()->DrawTexture("Platform2", GSvector2(590, 150));

	p_GameManager->GetRenderer2D()->DrawTexture("MaxCombo", GSvector2(610, 450));
	number.draw(GSvector2(1000, 460), p_GameManager->GetPlayerParameter().getMaxCombo(), 3);
	p_GameManager->GetRenderer2D()->DrawTexture("Retry", GSvector2(610, 550));
	number.draw(GSvector2(1000, 560), p_GameManager->GetPlayerParameter().getRetryCount(), 3);
	p_GameManager->GetRenderer2D()->DrawTexture("TotalScore", GSvector2(610, 650));
	number.draw(GSvector2(940, 660), p_GameManager->GetScore()->GetTotalScore(), 5);
	//大きいブロックの描画
	p_GameManager->GetRenderer2D()->DrawTexture("BigBlock2",m_Param);
}
//終了
void CreditEnd::End()
{
	gsStopMusic();
}

// 終了しているか？     
bool CreditEnd::IsEnd() const
{
	return is_End;
}

SceneName CreditEnd::Next() const {
	return SceneName::GameTitle;
}
void CreditEnd::SetName(const SceneName & name) {

}

SceneName CreditEnd::GetName() {
	return SceneName::ResultEnd;
}