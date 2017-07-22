#pragma once
#include "../../Utility/Animation/Animation.h"
#include "../../TextureContains/AnimationTexture/AnimationTexture.h"
#include <string.h>
#include <GSvector2.h>
class StartLogoAnimation {
public:
	StartLogoAnimation(
		Animation animation,
		std::string textureName,
		GSvector2 position);
	virtual void draw();
private:
	Animation *m_Animation;
	AnimationTexture *m_AnimationTexture;
};