#include "GameEnd.h"

#include <gslib.h>

// コンストラクタ    
GameEnd::GameEnd(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// 開始     
void GameEnd::OnStart(){}

// 更新     
void GameEnd::OnUpdate(float deltaTime){
	gsTextPos(100, 100);
	gsDrawText("end");
}
