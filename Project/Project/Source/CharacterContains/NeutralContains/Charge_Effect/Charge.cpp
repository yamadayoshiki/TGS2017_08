#include "Charge.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../ActorContains/Transform/Transform.h"
#include"../../PlayerContains/Player/Player.h"

Charge::Charge(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const Player_WPtr& player)
	:Actor(world, ActorName::Charge, position, gameManager),
	p_Player(player)
{
	p_Renderer = gameManager->GetRenderer2D();
}

//デストラクタ
Charge::~Charge()
{
	delete p_AnimationTexture;
}
//初期化
void Charge::initialize()
{
	m_Charge_Stage = Charge_Stage::Zero;
	p_Player.lock()->getParameter().m_ChargeConter = 0.0f;
	p_Player.lock()->getParameter().m_ChargePower = 0;


	//テクスチャの現在の名前の設定
	m_CurrrentName = "Charge0";
	m_PreviosName = m_CurrrentName;

	//アニメーションのパラメータの設定
	p_Animation = new Animation(*p_Renderer->GetTextureRect(m_CurrrentName), 64, 3);
	p_AnimationTexture = new AnimationTexture(m_CurrrentName, p_Renderer, p_Animation);
	p_AnimationTexture->Initialize();
}

//更新処理
void Charge::onUpdate(float deltaTime)
{
	//チャージ段階の更新
	ChargeUpdate();
	//プレイヤーのトランスフォームを取得
	p_Transform = p_Player.lock()->getTransform();
	//アニメーションの更新
	p_AnimationTexture->Update(deltaTime);
	//フラグがfalseなら死亡する
	if (p_Player.lock()->getParameter().getChargeFlag() == false) {
		//死亡
		dead();
	}
}

//描画処理
void Charge::onDraw()const
{
	p_AnimationTexture->GetParameter()->SetPosition(getPosition());
	p_AnimationTexture->GetParameter()->SetRotate(p_Transform->m_Angle);
	p_AnimationTexture->GetParameter()->SetCenter({ 32.0f, 32.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//アニメーションの描画
	p_AnimationTexture->Draw();
}

//チャージ段階の更新
void Charge::ChargeUpdate()
{
	switch (p_Player.lock()->getParameter().getChargePower())
	{
	case Charge_Stage::Zero:
		m_PreviosName = m_CurrrentName;
		m_CurrrentName = "Charge0";
		break;

	case Charge_Stage::Frist:
		m_PreviosName = m_CurrrentName;
		m_CurrrentName = "Charge1";
		break;

	case Charge_Stage::Second:
		m_PreviosName = m_CurrrentName;
		m_CurrrentName = "Charge2";
		break;

	case Charge_Stage::Third:
		m_PreviosName = m_CurrrentName;
		m_CurrrentName = "Charge3";
		break;
	}

	if (m_CurrrentName == m_PreviosName) return;
	//アニメーションのパラメータの再設定
	p_Animation = new Animation(*p_Renderer->GetTextureRect(m_CurrrentName), 64, 3);
	p_AnimationTexture->setName_Animation(m_CurrrentName, p_Animation);
}

