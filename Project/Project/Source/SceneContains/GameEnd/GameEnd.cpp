#include "GameEnd.h"

#include <gslib.h>

// �R���X�g���N�^    
GameEnd::GameEnd(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// �J�n     
void GameEnd::OnStart(){}

// �X�V     
void GameEnd::OnUpdate(float deltaTime){
	gsTextPos(100, 100);
	gsDrawText("end");
}
