#ifndef SCORE_H_
#define SCORE_H_

#include<gslib.h>
#include"../Rederer2D/Renderer2DPtr.h"

class Score
{
public:
	//�R���X�g���N�^
	Score();
	//������
	void initialze();
	//�X�R�A�̉��Z
	void AddScore(const int score);
	//�X�R�A�̐��l��n��
	int ReleaseScore();
	//���W�̐ݒ�
	void setPosition(const GSvector2& position);
	//�`��
	void draw(Renderer2DPtr& renderer)const;

private:
	int m_Score;
	//���W
	GSvector2 m_Position{0.0f,0.0f};
};
#endif // !SCORE_H_
