#include"Respawn.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"
//コンストラクタ
Respawn::Respawn(IWorld* world, const GSvector2& position, IGameManagerPtr gameManager,const DrawOrder order)
	:Actor(
		world,
		ActorName::Respawn,
		position,
		gameManager,
		std::make_shared<AnimationTexture>("Respawn",gameManager->GetDrawManager(),order,64,3)){
}
//デストラクタ
Respawn::~Respawn(){
}
//初期化
void Respawn::onInitialize(){
	p_Texture->GetParameter()->m_Center = { 32.0f,32.0f };
}
//更新処理
void Respawn::onUpdate(float deltaTime){
	if (p_Texture->GetLoopCount() >= 1) {
		//死亡
		dead();
	}
}
//描画処理
void Respawn::onDraw()const{
}