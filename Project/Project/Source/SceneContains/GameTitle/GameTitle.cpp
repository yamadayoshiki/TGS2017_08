#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"
#include "../../UIContains/UIManager/UIManager.h"
#include "../../ActorContains/ActorGroup.h"
#include"../../WorldContains/World/World.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"

// コンストラクタ    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager){

	gameManager->GetRenderer2D()->LoadTexture("logo", "Resource/Texture/UI/Title/logo.png");
}

// 開始     
void GameTitle::OnStart(){
	// UIの生成
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));
	p_GameManager->GetPlayerParameter().setRemaining(3);
}

// 更新
void GameTitle::OnUpdate(float deltaTime){
	gsTextPos(100, 100);
	gsDrawText("title");
}

void GameTitle::OnDraw()const
{
	p_GameManager->GetRenderer2D()->DrawTexture(
		"logo",
		GSvector2(SCREEN_SIZE / 2) - 
		GSvector2(p_GameManager->GetRenderer2D()->GetTextureRect("logo")->right, p_GameManager->GetRenderer2D()->GetTextureRect("logo")->bottom) / 2 - 
		GSvector2(0, 1) * 200
		);
}

