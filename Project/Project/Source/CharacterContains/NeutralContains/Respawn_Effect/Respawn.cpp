#include"Respawn.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"

//コンストラクタ
Respawn::Respawn(IWorld* world, const GSvector2& position, IGameManagerPtr gameManager)
	:Actor(world,ActorName::Respawn,position,gameManager)
{
	p_Renderer = gameManager->GetRenderer2D();
}
//デストラクタ
Respawn::~Respawn()
{
	delete p_AnimationTexture;
}
//初期化
void Respawn::initialize()
{
	//アニメーションのパラメータの設定
	Animation* animation = new Animation(*p_Renderer->GetTextureRect("Respawn"), 64, 3);
	p_AnimationTexture = new AnimationTexture("Respawn", p_Renderer, animation);
	p_AnimationTexture->Initialize();
}
//更新処理
void Respawn::onUpdate(float deltaTime)
{
	//アニメーションの更新
	p_AnimationTexture->Update(deltaTime);

	if (p_AnimationTexture->GetLoopCount() >= 1) {
		//死亡
		dead();
	}
}
//描画処理
void Respawn::onDraw()const
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