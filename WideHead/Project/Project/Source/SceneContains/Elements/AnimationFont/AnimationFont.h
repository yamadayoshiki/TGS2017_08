#ifndef ANIMATIONFONT_H_
#define ANIMATIONFONT_H_
#include "../../../ActorContains/Actor/Actor.h"
#include"../../../DrawManager/DrawManagerPtr.h"

class AnimationFont : public Actor
{
public:
	AnimationFont(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const std::string texName,
		const float updateFrame);
	~AnimationFont();

public:
	//更新
	void onUpdate(float deltaTime)override;

private:
	//ロゴのアニメーションタイマ
	float LogoTimer = 0;

	DrawManagerSPtr p_DrawManager;
};
#endif // !ANIMATIONFONT_H_
