#ifndef SCORE_H_
#define SCORE_H_

class Score
{
public:
	//�R���X�g���N�^
	Score();
	//������
	void initialze();
	//�X�R�A�̉��Z
	void AddScore(const int score);
	//�`��
	void draw()const;

private:
	int m_Score;
};
#endif // !SCORE_H_
