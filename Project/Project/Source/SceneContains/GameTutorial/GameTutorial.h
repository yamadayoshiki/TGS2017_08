#ifndef GAMETUTORIAL_H_
#define GAMETUTORIAL_H_

#include "../GamePlay/GamePlay.h"
class GameTutorial : public GamePlay
{
public:
	GameTutorial(const IGameManagerPtr& gameManager);

protected:
	// �Z�b�g�A�b�v
	void SetUp() override;
	//Map�f�[�^�̐ݒ�
	void MapSetDeta()override;

};

#endif // !GAAMETUTORIAL_H_
