#include "Animation.h"

//コンストラクタ
Animation::Animation(
	const GSrect& texRect,
	const float cutWidth,
	const unsigned int animmationUpdateTimer)
	: m_TexRect(texRect)
	, m_CutWidth(cutWidth)
	, m_AnimationUpdateTimer(animmationUpdateTimer)
	, m_CutRect(GSrect())
	, m_CurrentNum(0)
	, m_AnimationTimer(0)
{
	Initialize();
}

//デフォルトコンストラクタ
Animation::Animation()
	:Animation(GSrect(), 0.0f, 0) {
}

//デストラクタ
Animation::~Animation() {
}

//初期化
void Animation::Initialize() {
	m_AnimationTimer = 0;
	m_CurrentNum = 0;
	Change(m_CurrentNum);
}

//更新
void Animation::Update(float deltaTime) {
	//描画矩形変更
	if (m_CurrentNum != m_AnimationTimer / m_AnimationUpdateTimer)
	{
		m_CurrentNum++;
		Change(m_CurrentNum);
	}
	//時間更新
	m_AnimationTimer++;
}

//描画矩形変更
void Animation::Change(unsigned int num) {
	//結果
	GSrect result = GSrect();

	//縦幅設定
	result.top = m_TexRect.top;
	result.bottom = m_TexRect.bottom;

	//横幅設定
	result.left = m_CutWidth * num;
	result.right = result.left + m_CutWidth;

	//結果設定
	m_CutRect = result;
}

//描画矩形の取得
GSrect* Animation::GetCurrentRect() {
	return &m_CutRect;
}