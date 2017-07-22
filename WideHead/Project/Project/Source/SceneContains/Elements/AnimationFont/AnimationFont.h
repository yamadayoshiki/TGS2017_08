#ifndef ANIMATIONFONT_H_
#define ANIMATIONFONT_H_
#include "../../../ActorContains/Actor/Actor.h"
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
	//çXêV
	void onUpdate(float deltaTime)override;
};
#endif // !ANIMATIONFONT_H_
