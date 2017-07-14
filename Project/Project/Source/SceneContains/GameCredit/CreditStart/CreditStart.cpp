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
#include"../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include"../../../TextureContains/Texture/Texture.h"

CreditStart::CreditStart(IWorld* world, const IGameManagerPtr & gameManager)
	:p_World(world), p_GameManager(gameManager),p_Texture(std::make_shared<Texture>("BigBlock2",p_GameManager->GetDrawManager(),DrawOrder::UI))
{
	//パラメータの設定
	p_Texture->GetParameter()->m_Position = GSvector2(550, 100);
	p_Texture->GetParameter()->m_Center = { 0.0f,0.0f };
}

// 開始     
void CreditStart::Start()
{
	is_End = false;
}
// 更新     
void CreditStart::Update(float deltaTime)
{
	if (timer_ >= 60 * 2)
	{
		is_End = true;
	}

	timer_ += deltaTime;
}
//描画
void CreditStart::Draw()const
{
	
}
//終了
void CreditStart::End()
{

}

// 終了しているか？     
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