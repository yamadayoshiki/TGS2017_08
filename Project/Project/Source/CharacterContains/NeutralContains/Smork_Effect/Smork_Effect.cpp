#include "Smork_Effect.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"
#include"../../../Utility/Sound/SoundName.h"

Smork_Effect::Smork_Effect(
	IWorld * world,
	const GSvector2 & position,
	IGameManagerPtr gameManager)
	:Actor(world, ActorName::Explosion, position, gameManager) {
	p_Renderer = gameManager->GetRenderer2D();
}

//デストラクタ
Smork_Effect::~Smork_Effect()
{
	delete p_AnimationTexture;
}

//初期化
void Smork_Effect::initialize()
{
	//アニメーションのパラメータの設定
	Animation* animation = new Animation(*p_Renderer->GetTextureRect("BlockBreak"), 252, 3);
	p_AnimationTexture = new AnimationTexture("BlockBreak", p_Renderer, animation);
	p_AnimationTexture->Initialize();
	gsPlaySE(SE_BLOCK_BREAK);
}

//更新処理
void Smork_Effect::onUpdate(float deltaTime)
{
	//アニメーションの更新
	p_AnimationTexture->Update(deltaTime);

	if (p_AnimationTexture->GetLoopCount() >= 1) {
		//死亡
		dead();
	}
}

//描画処理
void Smork_Effect::onDraw()const
{
	//アニメーションのパラメータの設定
	p_AnimationTexture->GetParameter()->SetPosition(p_Transform->m_Position);
	p_AnimationTexture->GetParameter()->SetRotate(p_Transform->m_Angle - 90);
	p_AnimationTexture->GetParameter()->SetCenter({ 126.0f, 126.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//アニメーションの描画
	p_AnimationTexture->Draw();
}
