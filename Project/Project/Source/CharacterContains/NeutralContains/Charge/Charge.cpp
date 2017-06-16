#include "Charge.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"

Charge::Charge(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager)
	:Actor(world,ActorName::Charge,position,gameManager)
{
	p_Renderer = gameManager->GetRenderer2D();
}

//デストラクタ
Charge::~Charge()
{
	delete p_AnimationTexture;
	delete p_Animation;
}
//初期化
void Charge::initialize()
{
	//テクスチャの名前の設定
	m_Name = "Charge1";
	//アニメーションのパラメータの設定
	p_Animation = new Animation(*p_Renderer->GetTextureRect(m_Name), 64, 1);
	p_AnimationTexture = new AnimationTexture(m_Name, p_Renderer, p_Animation);
	p_AnimationTexture->Initialize();
}

//更新処理
void Charge::onUpdate(float deltaTime)
{
	//アニメーションの更新
	p_AnimationTexture->Update(deltaTime);

	const auto& player = p_World->findActor(ActorName::Player);
	if (player == nullptr)return;
	m_Transform = player->getTransform();
}

//描画処理
void Charge::onDraw()const
{
	p_AnimationTexture->GetParameter()->SetPosition(m_Transform.m_Position);
	p_AnimationTexture->GetParameter()->SetRotate(m_Transform.m_Angle - 90);
	p_AnimationTexture->GetParameter()->SetCenter({ 32.0f, 32.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//アニメーションの描画
	p_AnimationTexture->Draw();
}

