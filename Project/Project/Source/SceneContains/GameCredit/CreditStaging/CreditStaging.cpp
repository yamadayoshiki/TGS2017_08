#include "CreditStaging.h"

#include "../../../WorldContains/World/World.h"
#include"../../../ActorContains/ActorGroup.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../Utility/Sound/SoundName.h"
#include"../../../CharacterContains/NeutralContains/Smork_Effect/Smork_Effect.h"
#include"../BigBlock2.h"


CreditStaging::CreditStaging(){
}

CreditStaging::~CreditStaging(){
}

// 開始     
void CreditStaging::OnStart(){
	timer_ = 0.0f;
	p_World->addActor(ActorGroup::UI, std::make_shared<BigBlock2>(p_World.get(), p_GameManager));
}
// 更新     
void CreditStaging::OnUpdate(float deltaTime){
	if (timer_ >= 120.0f)Change(SceneName::CreditEnd);
	timer_ += deltaTime;
}
//描画
void CreditStaging::OnDraw()const{
}
//終了
void CreditStaging::OnEnd(){
}