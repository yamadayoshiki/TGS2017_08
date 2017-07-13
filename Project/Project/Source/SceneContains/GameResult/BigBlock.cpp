#include "BigBlock.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"

#include "../../Define/Def_Nagano.h"
#include <gslib.h>

//コンストラクタ
BigBlock::BigBlock(const IGameManagerPtr & gameManager)
	:Transition(gameManager){
}

// デストラクタ
BigBlock::~BigBlock() 
{
}

// 開始     
void BigBlock::onStart() 
{
	timer_ = 0.0f;
	//パラメータの設定
	m_Param.SetPosition(GSvector2(550, 300));
	m_Param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("BigBlock"));
	m_Param.SetCenter({ 0.0f, 0.0f });
	m_Param.SetColor(m_Color);
	m_Param.SetScale({ 1.0f, 1.0f });
	m_Param.SetRotate(0.0f);
}

//更新
void BigBlock::onUpdate(float deltaTime) 
{
	if (m_Color.a <= 0.5 || m_Color.a >= 1.0f) {
		m_Alpha = m_Alpha * -1;
	}
	m_Color.a = m_Color.a + m_Alpha;
	m_Param.SetColor(m_Color);

	float posX = gsRandf(-2, 2);
	float posY = gsRandf(-2, 2);
	m_Param.SetPosition(GSvector2(550 + posX, 300 + posY));

	if (timer_ >= 120.0f)
	{
		is_end = true;
	}
	timer_ += deltaTime;
}

//描画
void BigBlock::onDraw() const 
{
	//大きいブロックの描画
	p_GameManager->GetRenderer2D()->DrawTexture("BigBlock", m_Param);
}

bool BigBlock::isEnd() 
{
	return is_end;
}

