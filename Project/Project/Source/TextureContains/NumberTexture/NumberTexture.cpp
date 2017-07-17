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
	//�z�񏉊���
	m_ParamVector.clear();
	//�e�N�X�`���̕�����؂��蕝���Z�o
	GSrect rect = p_DrawManager.lock()->GetRect(m_TexName);
	m_CutHeight = rect.bottom;
	m_CutWidth = rect.right / 10;
	//�z��쐬
	ChangeLength(m_Length);
	SetNumber(0);
}

NumberTexture::~NumberTexture() {
	for (auto itr = m_ParamVector.begin(); itr != m_ParamVector.end(); itr++)
		p_DrawManager.lock()->Remove(itr->m_DrawOrderID);
	//�������J��
	std::vector<Texture2DParamAndID> a;
	m_ParamVector.swap(a);
	m_ParamVector.clear();
}

void NumberTexture::Initialize() {
	////�������J��
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
		std::cout << "�͈͊O";
}

void NumberTexture::SetPos(const GSvector2 & pos) {
	m_Position = pos;
	for (int i = 0; i < m_ParamVector.size(); i++)
		m_ParamVector[i].m_TexParam->m_Position = GetOneDigitPos(i + 1, pos);
}

void NumberTexture::SetNumberLocal(int num) {
	//����
	int digit = MathSupport::GetDigit(num);
	//�����ݒ�
	for (int i = 0; i < m_Length; i++) {
		//�؂�����1���̐���
		int cutNum = 0;
		if (i < digit)
			cutNum = MathSupport::GetCutNum(num, digit - i, 1);

		m_ParamVector[i].m_TexParam->m_Rect = GetNumToRect(cutNum);
	}
}

void NumberTexture::SetNumberLocalNonZero(int num) {
	//����
	int digit = MathSupport::GetDigit(num);
	//�����ύX
	if (digit != m_ParamVector.size())
		ChangeLength(digit);
	//�����ݒ�
	for (int i = 0; i < digit; i++) {
		//�؂�����1���̐���
		int cutNum = MathSupport::GetCutNum(num, digit - i, 1);
		m_ParamVector[i].m_TexParam->m_Rect = GetNumToRect(cutNum);
	}
}

GSrect NumberTexture::GetNumToRect(int num) {
	return GSrect(m_CutWidth*num, 0, m_CutWidth*(num + 1), m_CutHeight);
}

void NumberTexture::ChangeLength(const int length) {
	const int vecSize = m_ParamVector.size();
	//�g��
	if (vecSize < length)
		// i = vector�̔ԍ�
		for (int i = vecSize; i < length; i++)
		{
			Texture2DParamAndID paramAndID;
			paramAndID.m_DrawOrderID = p_DrawManager.lock()->RegisterDefaultParam(m_TexName, paramAndID.m_TexParam, m_DrawOrder);
			paramAndID.m_TexParam->m_Center = GSvector2(m_CutWidth / 2, m_CutHeight / 2);
			paramAndID.m_TexParam->m_Position = GetOneDigitPos(i + 1, m_Position);
			m_ParamVector.push_back(paramAndID);
		}

	//�k��
	else if (vecSize > length)
		// i = ����
		for (int i = vecSize; i > length; i--)
		{
			auto itr = m_ParamVector.begin() + (i - 1);
			//�`��Ǘ�����폜
			p_DrawManager.lock()->Remove(itr->m_DrawOrderID);

			m_ParamVector.erase(itr);
		}
}

GSvector2 NumberTexture::GetOneDigitPos(const int numDigit, const GSvector2& pos) {
	//�v�Z�̓s���㌅���炵
	int digit = numDigit - 1;
	return GSvector2(pos.x - ((m_CutWidth * digit) + m_CutWidth / 2), pos.y + (m_CutHeight / 2));
}
