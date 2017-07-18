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
#include"../../MapGenerator/MapGenerator.h"
#include "../../Utility/FourDirection/FourDirection.h"
#include"../../CharacterContains/Factory/CharacterFactory.h"
#include"../../Utility/Sound/SoundName.h"
#include "../../StagingContains/TransitionStaging/Transition/Transition.h"
#include"../../UIContains/UIManager/UIManager.h"
#include "../../UIContains/Number/Number.h"
#include "../../UIContains/Sprite/Sprite.h"
#include "../../UIContains/Button/Button.h"
#include "../SceneManager/SceneChildMgr.h"
#include "../../Utility/Score/Score.h"
#include "../GamePlay/Ready/GamePlayReady.h"
#include "../GamePlay/Play/GamePlayPlay.h"
#include "../GamePlay/Pause/GamePlayPause.h"
#include "../../WorldContains/EventMessage/EventMessage.h"

GameTutorial::GameTutorial(const IGameManagerPtr & gameManager)
	:GamePlay(gameManager) {
}

void GameTutorial::SetUp(){
	p_SceneChildMgr = std::make_unique<SceneChildMgr>(shared_from_this());
	p_SceneChildMgr->Add(SceneName::Start, std::make_shared<GamePlayReady>());
	p_SceneChildMgr->Add(SceneName::Play, std::make_shared<GamePlayPlay>());
	p_SceneChildMgr->Add(SceneName::Pause, std::make_shared<GamePlayPause>());
	p_SceneChildMgr->SetUp();
	p_SceneChildMgr->Change(SceneName::Start);
}

void GameTutorial::MapSetDeta() {
	//マップデータによる生成
	p_World->SetMapGenerator(p_World, p_GameManager);
	p_World->SetCharacterFactory(new CharacterFactory(p_World, p_GameManager));
	MapOrder = p_GameManager->get_MapOrder();
	p_World->generate(p_World, p_GameManager, "Resource/StreamingAssets/stage0.csv");
}
