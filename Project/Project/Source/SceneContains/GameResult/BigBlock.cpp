#include "BigBlock.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../Define/Def_Nagano.h"
#include "../../TextureContains/Texture/Texture.h"
#include"../../DrawManager/DrawManager.h"
#include <gslib.h>

//コンストラクタ
BigBlock::BigBlock(IWorld* world, const IGameManagerPtr & gameManager)
	:Actor(
		world,
		ActorName::UI_Sprite,
		GSvector2(550.0f,300.0f),
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
	p_Texture->GetParameter()->m_Position = GSvector2(550 + posX, 300 + posY);

	if (timer_ >= 120.0f)
	{
		is_end = true;
	}
	timer_ += deltaTime;
}