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
	//�X�V
	void onUpdate(float deltaTime)override;

private:
	//���S�̃A�j���[�V�����^�C�}
	float LogoTimer = 0;

	DrawManagerSPtr p_DrawManager;
};
#endif // !ANIMATIONFONT_H_
