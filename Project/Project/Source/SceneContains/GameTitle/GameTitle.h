#ifndef GAMETITLE_H_
#define GAMETITLE_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include"../../DrawManager/DrawManagerPtr.h"
#include"../../Utility/Rederer2D/Renderer2DPtr.h"

#include <iostream>
class AnimationTexture;
//�^�C�g���V�[��
class GameTitle : public Scene
{
public:
	// �R���X�g���N�^    
	GameTitle(const IGameManagerPtr& gameManager);

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	// �`��     
	virtual void OnDraw()const;
	//�I��
	virtual void OnEnd()override;

private:
	//���S�̃A�j���[�V�����^�C�}
	float LogoTimer = 0;

	//�����_���[
	Renderer2DPtr		p_Renderer;
	DrawManagerSPtr		p_DrawManager;
};

#endif