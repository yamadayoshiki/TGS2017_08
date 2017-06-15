#include "Score.h"

#include <gslib.h>
#include <GStype.h>
#include <sstream>
#include <algorithm>

//�R���X�g���N�^
Score::Score()
{
	initialze();
}

//������
void Score::initialze()
{
	m_Score = 0;
	m_Position = GSvector2(200, 50);
}

//�X�R�A�̉��Z
void Score::AddScore(const int score)
{
	m_Score += score;
}

int Score::ReleaseScore()
{
	return m_Score;
}

//���W�̐ݒ�
void Score::setPosition(const GSvector2& position)
{
	m_Position = position;
}

//�`��
void Score::draw() const
{
	std::stringstream ss;
	ss << "SCORE " << m_Score;

	// �p�����[�^�[�̕`��
	gsTextPos(m_Position.x + 100, m_Position.y);
	gsFontParameter(GS_FONT_BOLD, 50, "HG����B");
	gsDrawText(ss.str().c_str());

	// �p�����[�^��߂�
	gsFontParameter(GS_FONT_BOLD, 20, "HG����B");
}
