#ifndef ANIMATIONSPRITEBASE_H_
#define ANIMATIONSPRITEBASE_H_
#include "../../../ActorContains/Actor/Actor.h"
#include "../../../DrawManager/DisplayMode.h"
class AnimationSpriteBase : public Actor
{
public:
	AnimationSpriteBase(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const ITexturePtr& texture = std::make_shared<NullTexture>());

public:
	//ï`âÊï\é¶êÿë÷
	virtual void ChangeDisplayMode(const DisplayMode mode) = 0;
	//èIóπÇµÇΩÇ©
	virtual bool IsEnd()const = 0;
};
#endif // !ANIMATIONSPRITEBASE_H_
