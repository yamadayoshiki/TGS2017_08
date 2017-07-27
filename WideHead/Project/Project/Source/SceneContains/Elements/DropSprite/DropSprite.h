#ifndef DROPSPRITE_H_
#define DROPSPRITE_H_
#include "../../../ActorContains/Actor/Actor.h"
class DropSprite : public Actor
{
public:
	DropSprite(IWorld* world,
		const IGameManagerPtr& gameManager);
	~DropSprite();

protected:
	void onUpdate(float deltaTime) override;

public:
	void Skip();
};
#endif