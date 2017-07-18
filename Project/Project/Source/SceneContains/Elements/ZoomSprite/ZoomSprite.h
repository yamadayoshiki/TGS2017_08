#ifndef ZOOMSPRITE_H_
#define ZOOMSPRITE_H_
#include "../../../ActorContains/Actor/Actor.h"

class ZoomSprite : public Actor
{
private:
	enum State {
		UP,		//ägëÂ
		DOWN,	//èkè¨
		END,	//èIóπ
	};
public:
	ZoomSprite(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const ITexturePtr& texture);

protected:
	void onUpdate(float deltaTime) override;

protected:
	State m_CurState;
	float m_Scale;
};
#endif // !ZOOMSPRITE_H_
