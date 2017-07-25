#ifndef STARTLOGOANIMATIONFONT_H_
#define STARTLOGOANIMATIONFONT_H_
#include "../../../ActorContains/Actor/Actor.h"
#include"../../../DrawManager/DrawManagerPtr.h"
#include"../../../Utility/Rederer2D/Renderer2DPtr.h"

class StartLogoAnimationFont : public Actor
{
public:
	StartLogoAnimationFont(
		IWorld* world,
	 	const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const std::string texName,
		const int updateFrame);
	~StartLogoAnimationFont();

public:
	//更新
	void onUpdate(float deltaTime)override;

private:
	//ロゴのアニメーションタイマ
	float LogoTimer = 0;

	//レンダラー
	//Renderer2DPtr		p_Renderer;
	DrawManagerSPtr		p_DrawManager;
};
#endif // !ANIMATIONFONT_H_
