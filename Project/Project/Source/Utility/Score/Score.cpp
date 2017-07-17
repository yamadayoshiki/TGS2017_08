#include "Score.h"

#include <gslib.h>
#include <GStype.h>
#include <sstream>
#include <algorithm>
#include"../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../Rederer2D/Renderer2D.h"
#include"../Texture2DParameter/Texture2DParameter.h"


//�R���X�g���N�^
Score::Score() {
	initialze();
}

//������
void Score::initialze() {
	m_Score = 0;
	m_Total_Score = 0;
	m_Position = GSvector2(200, 50);
}

//�X�R�A�̉��Z
void Score::AddScore(const int score) {
	m_Score = std::min(m_Score + score, 99999);
	m_Total_Score = std::min(m_Total_Score + score, 99999);
}

int Score::ReleaseScore() {
	return m_Score;
}

//�g�[�^���X�R�A�̎擾
int Score::GetTotalScore() {
	return m_Total_Score;
}

//�X�R�A�̃��Z�b�g
void Score::ScoreRest() {
	m_Score = 0;
}

//���W�̐ݒ�
void Score::setPosition(const GSvector2& position) {
	m_Position = position;
}