#ifndef ENEMY07_H_
#define ENEMY07_H_

#include "../Base/EnemyBase.h"

//�m�R�m�R
class Enemy07 : public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy07(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const IGameManagerPtr& gameManager,
		const std::string fileName = "");
	//�f�X�g���N�^
	~Enemy07();
	//csv�Ő���(�g�p���p�����override)
	virtual ActorPtr CsvGenerate(const int x, const int y, const int csvparam) override;

protected:
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() override;
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() override;
	//�`��
	virtual void onDraw() const override;

protected:
	std::string m_FileName;	//������Wcsv�̃t�@�C���̖��O
};

#endif // !ENEMY07_H_
