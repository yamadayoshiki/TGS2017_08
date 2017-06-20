#include "Crush_Effect.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"

//コンストラクタ
Crush_Effect::Crush_Effect(IWorld * world, const GSvector2 & position, IGameManagerPtr gameManager)
	:Actor(world, ActorName::Crush, position, gameManager)
{
	p_Renderer = gameManager->GetRenderer2D();
}

//デストラクタ
Crush_Effect::~Crush_Effect()
{
	delete p_AnimationTexture;
}

//初期化
void Crush_Effect::initialize()
{
	//アニメーションのパラメータの設定
	Animation* animation = new Animation(*p_Renderer->GetTextureRect("Crush"), 32, 3);
	p_AnimationTexture = new AnimationTexture("Crush", p_Renderer, animation);
	p_AnimationTexture->Initialize();
}

//更新処理
void Crush_Effect::onUpdate(float deltaTime)
{
	//アニメーションの更新
	p_AnimationTexture->Update(deltaTime);

	if (p_AnimationTexture->GetLoopCount() >= 1) {
		//死亡
		dead();
	}
}

//描画処理
void Crush_Effect::onDraw()const
{
	//アニメーションのパラメータの設定
	p_AnimationTexture->GetParameter()->SetPosition(p_Transform->m_Position);
	p_AnimationTexture->GetParameter()->SetRotate(p_Transform->m_Angle - 90);
	p_AnimationTexture->GetParameter()->SetCenter({ 16.0f, 16.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//アニメーションの描画
	p_AnimationTexture->Draw();
}