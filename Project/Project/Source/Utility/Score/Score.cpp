#include "Score.h"

#include <gslib.h>
#include <GStype.h>
#include <sstream>
#include <algorithm>
#include"../Number/NumberTexture.h"
#include"../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../Rederer2D/Renderer2D.h"
#include"../Texture2DParameter/Texture2DParameter.h"


//�R���X�g���N�^
Score::Score()
{
	initialze();
}

//������
void Score::initialze()
{
	gsLoadTexture((GSuint)1000, "Resource/Texture/UI/Play/suuji");

	m_Score = 0;
	m_Position = GSvector2(200, 50);
}

//�X�R�A�̉��Z
void Score::AddScore(const int score)
{
	m_Score = std::min(m_Score + score, 9999999);
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
void Score::draw(Renderer2DPtr& renderer) const
{
	static const NumberTexture number(1000, 40, 60);
	Texture2DParameter param;
	param.SetPosition({ 130,m_Position.y });
	param.SetScale({ 1.0f,1.0f });
	renderer->DrawTexture("score_font", GSvector2(m_Position.x - 100,m_Position.y));
	number.draw(GSvector2(m_Position.x + 100, m_Position.y),m_Score,5);
	//std::stringstream ss;
	//ss << "SCORE " << m_Score;

	//// �p�����[�^�[�̕`��
	//gsTextPos(m_Position.x + 100, m_Position.y);
	//gsFontParameter(GS_FONT_BOLD, 50, "HG����B");
	//gsDrawText(ss.str().c_str());

	//// �p�����[�^��߂�
	//gsFontParameter(GS_FONT_BOLD, 20, "HG����B");
}
