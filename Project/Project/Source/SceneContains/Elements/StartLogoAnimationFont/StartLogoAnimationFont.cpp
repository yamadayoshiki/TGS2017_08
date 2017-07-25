#include "StartLogoAnimationFont.h"
#include "../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include"../../../DrawManager/DrawManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include <GSvector2.h>

StartLogoAnimationFont::StartLogoAnimationFont(IWorld * world,
	const GSvector2 & position, 
	const IGameManagerPtr & gameManager,
	const std::string texName, 
	const int updateFrame)
	: Actor(
		world,
		ActorName::UI_Sprite,
		GSvector2(position),
		gameManager,
		std::make_shared<AnimationTexture>(texName, gameManager->GetDrawManager(), DrawOrder::UI_Front1, 50, updateFrame)),
		p_DrawManager(gameManager->GetDrawManager()),
		LogoTimer{0} 
{
	//p_Texture->Stop();
}

StartLogoAnimationFont::~StartLogoAnimationFont() {
}

void StartLogoAnimationFont::onUpdate(float deltaTime) {
	//LogoTimer+=deltaTime;
	//if (LogoTimer >= 0 && LogoTimer <= 60)
	//{
	//	p_Texture->Restart();
	//}
	//else if (LogoTimer >= 168 && LogoTimer <= 218)
	//{
	//	p_Texture->Stop();
	//}
	//else if(LogoTimer >=218)
	//{
	//	p_Texture->Restart();
	//	LogoTimer = 0;
	//	return;
	//}
}