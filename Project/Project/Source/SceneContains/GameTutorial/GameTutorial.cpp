#include "GameTutorial.h"

#include <gslib.h>
#include<GSmusic.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include "../../Define/Def_Nakayama.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Utility/Score/Score.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../../Utility/FourDirection/FourDirection.h"
#include"../../CharacterContains/Factory/CharacterFactory.h"
#include"../../Utility/Sound/SoundName.h"

GameTutorial::GameTutorial(const IGameManagerPtr & gameManager)
	:Scene(gameManager){
}

void GameTutorial::OnStart()
{
	p_World->SetMapGenerator(p_World, p_GameManager);
	p_World->SetCharacterFactory(new CharacterFactory(p_World, p_GameManager));
	MapOrder = p_GameManager->get_MapOrder();

	p_GameManager->GetPlayerParameter().setRemaining(3);

	gsBindMusic(BGM_GAME_PLAY);

	PauseFlag = false;
}

void GameTutorial::OnUpdate(float deltaTime)
{
}

void GameTutorial::OnDraw() const
{
}

void GameTutorial::End()
{
	p_GameManager->set_MapOrder(MapOrder);
}
