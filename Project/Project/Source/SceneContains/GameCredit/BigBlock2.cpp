#include "BigBlock2.h"

#include"../../ActorContains/ActorGroup.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../Define/Def_Nagano.h"
#include "../../TextureContains/Texture/Texture.h"
#include"../../DrawManager/DrawManager.h"
#include"../../CharacterContains/NeutralContains/Smork_Effect/Smork_Effect.h"
#include <gslib.h>

//コンストラクタ
BigBlock2::BigBlock2(IWorld* world, const IGameManagerPtr& gameManager)
	:Actor(
		world,
		ActorName::UI_Sprite,
		GSvector2(850, 500),
		gameManager,
		std::make_shared<Texture>("BigBlock2", gameManager->GetDrawManager(), DrawOrder::UI_Front1)) {
	p_Texture->GetParameter()->m_Color.a = 1.0f;
	p_Texture->GetParameter()->m_Position = GSvector2(850, 500);
	timer_ = 0.0f;
}
// デストラクタ
BigBlock2::~BigBlock2(){
}

//更新
void BigBlock2::onUpdate(float deltaTime)
{
	if (p_Texture->GetParameter()->m_Color.a <= 0.5 || p_Texture->GetParameter()->m_Color.a >= 1.0f) {
		m_Alpha = m_Alpha * -1;
	}
	p_Texture->GetParameter()->m_Color.a += m_Alpha;

	float posX = gsRandf(-2, 2);
	float posY = gsRandf(-2, 2);
	p_Texture->GetParameter()->m_Position = GSvector2(550 + posX, 100 + posY);

	if ((int)timer_ % 4 == 0 && timer_ <= 120.0f) {
		float posX = gsRandf(-300, 300);
		float posY = gsRandf(-350, 350);
		GSvector2 position = GSvector2(700 + posX, 500 + posY);
		p_World->addActor(ActorGroup::Effect, std::make_shared<Smork_Effect>(p_World, position, p_GameManager));
	}

	if (timer_ >= 120.0f)
	{
		p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
	}
	timer_ += deltaTime;
}