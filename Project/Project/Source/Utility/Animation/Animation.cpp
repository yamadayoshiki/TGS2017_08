#include "Animation.h"

//�R���X�g���N�^
Animation::Animation(
	const GSrect& texRect,
	const float cutWidth,
	const float animmationUpdateTimer)
	: m_TexRect(texRect)
	, m_CutWidth(cutWidth)
	, m_AnimationUpdateTimer(animmationUpdateTimer)
	, m_CutRect(GSrect())
	, m_CurrentNum(0)
	, m_AnimationTimer(0.0f)
	, m_LoopCount(0)
{
	Initialize();
}


//�f�t�H���g�R���X�g���N�^
Animation::Animation()
	:Animation(GSrect(), 0.0f, 0.0f) {
}

//�f�X�g���N�^
Animation::~Animation() {
}

//������
void Animation::Initialize() {
	m_AnimationTimer = 0.0f;
	m_CurrentNum = 0;
	m_LoopCount = 0;
	Change();
}

//�X�V
void Animation::Update(float deltaTime) {
	//�`���`�ύX
	if (m_CurrentNum != (int)(m_AnimationTimer / m_AnimationUpdateTimer))
	{
		m_CurrentNum++;
		Change();
	}
	//���ԍX�V
	m_AnimationTimer += deltaTime;
}

//�`���`�ύX
void Animation::Change() {
	//����
	GSrect result = GSrect();

	result.top = m_TexRect.top;
	result.bottom = m_TexRect.bottom;

	//�����ݒ�
	float left = m_CutWidth * m_CurrentNum;
	if (left >= m_TexRect.right)
	{
		m_LoopCount++;
		m_AnimationTimer = 0.0f;
		m_CurrentNum = 0;
		left = m_CutWidth * (m_CurrentNum);
	}
	result.left = left;
	result.right = result.left + m_CutWidth;

	//���ʐݒ�
	m_CutRect = result;
}

//�`���`�̎擾
GSrect* Animation::GetCurrentRect() {
	return &m_CutRect;
}

//���[�v�񐔂̎擾
unsigned int Animation::GetLoopCount() {
	return m_LoopCount;
}

AnimationSPtr Animation::Clone(){
	AnimationSPtr result = std::make_shared<Animation>(m_TexRect, m_CutWidth, m_AnimationTimer);
	result->m_CutRect = m_CutRect;
	result->m_CurrentNum = m_CurrentNum;
	result->m_AnimationTimer = m_AnimationTimer;
	result->m_LoopCount = m_LoopCount;
	return result;
}
//�؂����`�̉����̎擾
float Animation::GetCutWidth() const{
	return m_CutWidth;
}
