#include "Repel_Effect.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"

Repel_Effect::Repel_Effect(
	IWorld * world, 
	const GSvector2 & position,
	IGameManagerPtr gameManager) 
	:Actor(world, ActorName::Explosion, position, gameManager) {
	p_Renderer = gameManager->GetRenderer2D();
}

//デストラクタ
Repel_Effect::~Repel_Effect()
{
	delete p_AnimationTexture;
}

//初期化
void Repel_Effect::initialize()
{
	//アニメーションのパラメータの設定
	Animation* animation = new Animation(*p_Renderer->GetTextureRect("Repel"), 64, 3);
	p_AnimationTexture = new AnimationTexture("Repel", p_Renderer, animation);
	p_AnimationTexture->Initialize();
}

//更新処理
void Repel_Effect::onUpdate(float deltaTime)
{
	//アニメーションの更新
	p_AnimationTexture->Update(deltaTime);

	if (p_AnimationTexture->GetLoopCount() >= 1) {
		//死亡
		dead();
	}
}

//描画処理
void Repel_Effect::onDraw()const
{
	//アニメーションのパラメータの設定
	p_AnimationTexture->GetParameter()->SetPosition(p_Transform->m_Position);
	p_AnimationTexture->GetParameter()->SetRotate(p_Transform->m_Angle - 90);
	p_AnimationTexture->GetParameter()->SetCenter({ 32.0f, 32.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//アニメーションの描画
	p_AnimationTexture->Draw();
}