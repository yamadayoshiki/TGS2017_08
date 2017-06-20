#include "Neutral_Explosion.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"

//コンストラクタ
Neutral_Explosion::Neutral_Explosion(
	IWorld* world,
	const GSvector2& position,
	IGameManagerPtr gameManager)
	:Actor(world, ActorName::Explosion, position, gameManager) {
	p_Renderer = gameManager->GetRenderer2D();
}

//デストラクタ
Neutral_Explosion::~Neutral_Explosion()
{
	delete p_AnimationTexture;
}

//初期化
void Neutral_Explosion::initialize()
{
	//アニメーションのパラメータの設定
	Animation* animation = new Animation(*p_Renderer->GetTextureRect("Explosion"), 64, 1);
	p_AnimationTexture = new AnimationTexture("Explosion", p_Renderer, animation);
	p_AnimationTexture->Initialize();
}

//更新処理
void Neutral_Explosion::onUpdate(float deltaTime)
{
	//アニメーションの更新
	p_AnimationTexture->Update(deltaTime);

	if (p_AnimationTexture->GetLoopCount() >= 1) {
		//死亡
		dead();
	}
}

//描画処理
void Neutral_Explosion::onDraw()const
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