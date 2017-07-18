#include "GameCredit.h"

#include <gslib.h>
#include<GSmusic.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../Utility/Rederer2D/Renderer2D.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/Sound/SoundName.h"
#include"../../Utility/Score/Score.h"
#include"../../UIContains/UIManager/UIManager.h"
#include"../../Utility/EnumRap/EnumRap.h"
#include"../../TextureContains/Texture/Texture.h"
#include"../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../DrawManager/DisplayMode.h"

#include"CreditStart\CreditStart.h"
#include"CreditStaging\CreditStaging.h"
#include"CreditEnd\CreditEnd.h"

// �R���X�g���N�^    
GameCredit::GameCredit(const IGameManagerPtr& gameManager)
	:Scene(gameManager){
}
// �J�n     
void GameCredit::OnStart() {
	MapOrder = p_GameManager->get_MapOrder();

	//m_SceneManager = new SceneManager();
	//m_SceneManager->Initialize();

	////�V�[���̒ǉ�
	//m_SceneManager->Add(SceneName::CreditStart, std::make_shared<CreditStart>(p_World.get(), p_GameManager));
	//m_SceneManager->Add(SceneName::ResultStaging, std::make_shared<CreditStaging>(p_World.get(), p_GameManager));
	//m_SceneManager->Add(SceneName::ResultEnd, std::make_shared<CreditEnd>(p_World.get(), p_GameManager));

	//m_SceneManager->Change(SceneName::CreditStart);

	//BGM�̐ݒ�
	gsBindMusic(BGM_GAME_CLER);
	//BGM�Đ�
	gsPlayMusic();

	//p_Texture->ChangeDisplayMode(DisplayMode::Display);
}

// �X�V     
void GameCredit::OnUpdate(float deltaTime) {

	//m_SceneManager->Update(deltaTime);
}

void GameCredit::OnDraw() const{
}

void GameCredit::OnEnd(){
	gsStopMusic();
}