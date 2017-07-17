#include "NumberTexture.h"
#include "NumberTexture.h"
#include "../../DrawManager/DrawManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../Utility/MathSupport/MathSupport.h"
NumberTexture::NumberTexture(
	const std::string & texName,
	const DrawManagerSPtr & drawManager,
	const DrawOrder drawOrder,
	const GSvector2 & pos,
	const int length)
	: m_TexName(texName)
	, p_DrawManager(drawManager)
	, m_DrawOrder(drawOrder)
	, m_Position(pos)
	, m_Length(length)
	, m_Number(-1) {
	//配列初期化
	m_ParamVector.clear();
	//テクスチャの幅から切り取り幅を算出
	GSrect rect = p_DrawManager.lock()->GetRect(m_TexName);
	m_CutHeight = rect.bottom;
	m_CutWidth = rect.right / 10;
	//配列作成
	ChangeLength(m_Length);
	SetNumber(0);
}

NumberTexture::~NumberTexture() {
	for (auto itr = m_ParamVector.begin(); itr != m_ParamVector.end(); itr++)
		p_DrawManager.lock()->Remove(itr->m_DrawOrderID);
	//メモリ開放
	std::vector<Texture2DParamAndID> a;
	m_ParamVector.swap(a);
	m_ParamVector.clear();
}

void NumberTexture::Initialize() {
	////メモリ開放
	//std::vector<Texture2DParamAndID> a;
	//m_ParamVector.swap(a);
	//m_ParamVector.clear();
	SetNumber(0);
}

void NumberTexture::ChangeDisplayMode(const DisplayMode mode) {
	for (auto itr = m_ParamVector.begin(); itr != m_ParamVector.end(); itr++)
		p_DrawManager.lock()->ChageDisplayMode(itr->m_DrawOrderID, mode);
}

void NumberTexture::SetNumber(int num) {
	if (num == m_Number)return;
	m_Number = num;
	if (m_Length > 0)
		SetNumberLocal(num);
	else if (m_Length == 0)
		SetNumberLocalNonZero(num);
	else
		std::cout << "範囲外";
}

void NumberTexture::SetPos(const GSvector2 & pos) {
	m_Position = pos;
	for (int i = 0; i < m_ParamVector.size(); i++)
		m_ParamVector[i].m_TexParam->m_Position = GetOneDigitPos(i + 1, pos);
}

void NumberTexture::SetNumberLocal(int num) {
	//桁数
	int digit = MathSupport::GetDigit(num);
	//数字設定
	for (int i = 0; i < m_Length; i++) {
		//切り取った1桁の数字
		int cutNum = 0;
		if (i < digit)
			cutNum = MathSupport::GetCutNum(num, digit - i, 1);

		m_ParamVector[i].m_TexParam->m_Rect = GetNumToRect(cutNum);
	}
}

void NumberTexture::SetNumberLocalNonZero(int num) {
	//桁数
	int digit = MathSupport::GetDigit(num);
	//桁数変更
	if (digit != m_ParamVector.size())
		ChangeLength(digit);
	//数字設定
	for (int i = 0; i < digit; i++) {
		//切り取った1桁の数字
		int cutNum = MathSupport::GetCutNum(num, digit - i, 1);
		m_ParamVector[i].m_TexParam->m_Rect = GetNumToRect(cutNum);
	}
}

GSrect NumberTexture::GetNumToRect(int num) {
	return GSrect(m_CutWidth*num, 0, m_CutWidth*(num + 1), m_CutHeight);
}

void NumberTexture::ChangeLength(const int length) {
	const int vecSize = m_ParamVector.size();
	//拡張
	if (vecSize < length)
		// i = vectorの番号
		for (int i = vecSize; i < length; i++)
		{
			Texture2DParamAndID paramAndID;
			paramAndID.m_DrawOrderID = p_DrawManager.lock()->RegisterDefaultParam(m_TexName, paramAndID.m_TexParam, m_DrawOrder);
			paramAndID.m_TexParam->m_Center = GSvector2(m_CutWidth / 2, m_CutHeight / 2);
			paramAndID.m_TexParam->m_Position = GetOneDigitPos(i + 1, m_Position);
			m_ParamVector.push_back(paramAndID);
		}

	//縮小
	else if (vecSize > length)
		// i = 桁数
		for (int i = vecSize; i > length; i--)
		{
			auto itr = m_ParamVector.begin() + (i - 1);
			//描画管理から削除
			p_DrawManager.lock()->Remove(itr->m_DrawOrderID);

			m_ParamVector.erase(itr);
		}
}

GSvector2 NumberTexture::GetOneDigitPos(const int numDigit, const GSvector2& pos) {
	//計算の都合上桁ずらし
	int digit = numDigit - 1;
	return GSvector2(pos.x - ((m_CutWidth * digit) + m_CutWidth / 2), pos.y + (m_CutHeight / 2));
}
