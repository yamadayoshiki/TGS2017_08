#include "BigBlock.h"

#include"../../ActorContains/ActorGroup.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../Define/Def_Nagano.h"
#include "../../TextureContains/Texture/Texture.h"
#include"../../DrawManager/DrawManager.h"
#include"../../CharacterContains/NeutralContains/Smork_Effect/Smork_Effect.h"
#include <gslib.h>

//コンストラクタ
BigBlock::BigBlock(IWorld* world, const IGameManagerPtr & gameManager)
	:Actor(
		world,
		ActorName::UI_Sprite,
		GSvector2(800.0f,500.0f),
		gameManager,
		std::make_shared<Texture>("BigBlock",gameManager->GetDrawManager(),DrawOrder::UI_Front1)){
	p_Texture->GetParameter()->m_Color.a = 1.0f;
	timer_ = 0.0f;
}

// デストラクタ
BigBlock::~BigBlock() {
}

//更新
void BigBlock::onUpdate(float deltaTime)
{
	if (p_Texture->GetParameter()->m_Color.a <= 0.5 || p_Texture->GetParameter()->m_Color.a >= 1.0f) {
		m_Alpha = m_Alpha * -1;
	}
	p_Texture->GetParameter()->m_Color.a += m_Alpha;

	float posX = gsRandf(-2, 2);
	float posY = gsRandf(-2, 2);
	p_Texture->GetParameter()->m_Position = GSvector2(800 + posX, 500 + posY);

	if (timer_ / 4 == 0) {
		float posX = gsRandf(-300, 300);
		float posY = gsRandf(-250, 250);
		GSvector2 position = GSvector2(800 + posX, 500 + posY);
		p_World->addActor(ActorGroup::Effect, std::make_shared<Smork_Effect>(p_World, position, p_GameManager));
	}

	if (timer_ >= 120.0f)
	{
		p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
	}
	timer_ += deltaTime;
}