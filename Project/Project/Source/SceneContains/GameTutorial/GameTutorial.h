#ifndef GAMETUTORIAL_H_
#define GAMETUTORIAL_H_

#include "../GamePlay/GamePlay.h"
class GameTutorial : public GamePlay
{
public:
	GameTutorial(const IGameManagerPtr& gameManager);

protected:
	// セットアップ
	void SetUp() override;
	//Mapデータの設定
	void MapSetDeta()override;

};

#endif // !GAAMETUTORIAL_H_
