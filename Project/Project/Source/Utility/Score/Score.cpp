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
}

//�X�R�A�̉��Z
void Score::AddScore(const int score)
{
	m_Score += score;
}

//�`��
void Score::draw() const
{
	std::stringstream ss;
	ss << "SCORE " << m_Score;
	// �摜�̕`��
	GSvector2 pos = GSvector2(200, 50);

	// �p�����[�^�[�̕`��
	gsTextPos(pos.x + 100, pos.y);
	gsFontParameter(GS_FONT_BOLD, 50, "HG����B");
	gsDrawText(ss.str().c_str());

	// �p�����[�^��߂�
	gsFontParameter(GS_FONT_BOLD, 20, "HG����B");
}
