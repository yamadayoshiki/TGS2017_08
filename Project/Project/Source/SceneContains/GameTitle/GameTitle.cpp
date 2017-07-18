#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"
#include "../../UIContains/UIManager/UIManager.h"
#include "../../ActorContains/ActorGroup.h"
#include"../../WorldContains/World/World.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include"../../Utility/Score/Score.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/InputState/InputState.h"
#include"../../Utility/Sound/SoundName.h"
#include"../../Utility/Animation/Animation.h"
#include "../../DrawManager/DrawManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../Elements/DropSprite/DropSprite.h"

#include<GSmusic.h>

// �R���X�g���N�^    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// �J�n     
void GameTitle::OnStart() {
	p_GameManager->GetPlayerParameter().setRemaining(3);
	p_GameManager->GetScore()->initialze();
	MapOrder = 0;
	p_GameManager->set_MapOrder(MapOrder);

	//UI����
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));
	p_World->addActor(ActorGroup::UI, std::make_shared<DropSprite>(p_World.get(), p_GameManager));

	gsBindMusic(BGM_GAME_TITLE);
	gsPlayMusic();
}

// �X�V
void GameTitle::OnUpdate(float deltaTime) {
	//B�{�^���ŃQ�[���v���C��
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) || p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		gsPlaySE(SE_DECITION);
		p_World->EndRequest(SceneName::GamePlay);
	}
}

void GameTitle::OnDraw()const{
}

void GameTitle::OnEnd(){
	gsStopMusic();
	p_GameManager->set_MapOrder(MapOrder);
}