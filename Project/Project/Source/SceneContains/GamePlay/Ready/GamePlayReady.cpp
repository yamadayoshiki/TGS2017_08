#include "GamePlayReady.h"

GamePlayReady::GamePlayReady() {
}

GamePlayReady::~GamePlayReady() {
}

void GamePlayReady::OnStart() {
}

void GamePlayReady::OnUpdate(float deltaTime) {
	Change(SceneName::GamePlay);
}

void GamePlayReady::OnDraw() const {
}

void GamePlayReady::OnEnd() {
}
