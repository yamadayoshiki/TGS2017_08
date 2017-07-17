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
	, m_LoopCount(0)
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
	m_LoopCount = 0;
	Change();
}

//更新
void Animation::Update(float deltaTime) {
	//描画矩形変更
	if (m_CurrentNum != m_AnimationTimer / m_AnimationUpdateTimer)
	{
		m_CurrentNum++;
		Change();
	}
	//時間更新
	m_AnimationTimer++;
}

//描画矩形変更
void Animation::Change() {
	//結果
	GSrect result = GSrect();

	result.top = m_TexRect.top;
	result.bottom = m_TexRect.bottom;

	//横幅設定
	float left = m_CutWidth * m_CurrentNum;
	if (left >= m_TexRect.right)
	{
		m_LoopCount++;
		m_AnimationTimer = 0;
		//m_CurrentNum = 0;
		left = m_CutWidth * (m_CurrentNum);
	}
	result.left = left;
	result.right = result.left + m_CutWidth;

	//結果設定
	m_CutRect = result;
}

//描画矩形の取得
GSrect* Animation::GetCurrentRect() {
	return &m_CutRect;
}

//ループ回数の取得
unsigned int Animation::GetLoopCount() {
	return m_LoopCount;
}