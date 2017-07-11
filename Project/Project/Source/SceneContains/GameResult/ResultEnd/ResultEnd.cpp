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

ResultEnd::ResultEnd(IWorld* world, const IGameManagerPtr & gameManager)
	:p_World(world), p_GameManager(gameManager)
{
}

// 開始     
void ResultEnd::Start()
{
	// UIの生成
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, SceneName::GameResult));

	MapOrder = p_GameManager->get_MapOrder();
	is_End = false;
	m_Score = 0;

	//パラメータの設定
	m_Param.SetPosition(GSvector2(550, 300));
	m_Param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("BigBlock"));
	m_Param.SetColor(m_Color);
	m_Param.SetScale({ 1.0f,1.0f });
	m_Param.SetCenter({ 0.0f,0.0f });
	m_Param.SetRotate(0.0f);
}
// 更新     
void ResultEnd::Update(float deltaTime)
{
	float t = timer_ / maxTimer_;
	GScolor color = m_Color.lerp(GScolor(1.0f, 1.0f, 1.0f, 0.0f), t);
	m_Param.SetColor(color);

	if (timer_ >= 60 * 5)
	{
		//次のステージがない場合ゲームクリアへ遷移
		if (MapOrder == 11) {
			p_World->EndRequest(SceneName::GameCredit);
			return;
		}
		MapOrder += 1;
		p_GameManager->set_MapOrder(MapOrder);
		gsStopMusic();
		p_World->EndRequest(SceneName::GamePlay);
	}

	//if (p_GameManager->GetScore()->ReleaseScore() != m_Score && color.a <= 0.0f)
	//{
	//	m_Score += 1;
	//}

	timer_ += deltaTime;
}
//描画
void ResultEnd::Draw()const
{
	//static const NumberTexture number(1000, 40, 60);

	p_GameManager->GetRenderer2D()->DrawTexture("Platform", GSvector2(625, 450));
	//リザルトスコアの描画
	//number.draw(GSvector2(780, 650),m_Score, 5);
	p_GameManager->GetScore()->setPosition(GSvector2(750, 650));
	p_GameManager->GetScore()->draw(p_GameManager->GetRenderer2D());

	//大きいブロックの描画
	p_GameManager->GetRenderer2D()->DrawTexture("BigBlock", m_Param);
}
//終了
void ResultEnd::End()
{
	gsStopMusic();
}

// 終了しているか？     
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