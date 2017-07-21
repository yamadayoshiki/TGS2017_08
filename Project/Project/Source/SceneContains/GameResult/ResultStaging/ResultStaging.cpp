#include "ResultStaging.h"

#include "../../../WorldContains/World/World.h"
#include"../../../ActorContains/ActorGroup.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../Utility/Sound/SoundName.h"
#include"../../../CharacterContains/NeutralContains/Smork_Effect/Smork_Effect.h"
#include"../BigBlock.h"


ResultStaging::ResultStaging() {
}

ResultStaging::~ResultStaging() {
}

// 開始     
void ResultStaging::OnStart() {
	timer_ = 0.0f;
	p_World->addActor(ActorGroup::UI, std::make_shared<BigBlock>(p_World.get(), p_GameManager));
}
// 更新     
void ResultStaging::OnUpdate(float deltaTime) {
	if (timer_ >= 120.0f || p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B)) {
		Change(SceneName::ResultEnd);
	}
	timer_ += deltaTime;
}
//描画
void ResultStaging::OnDraw()const {
}
//終了
void ResultStaging::OnEnd() {
}
