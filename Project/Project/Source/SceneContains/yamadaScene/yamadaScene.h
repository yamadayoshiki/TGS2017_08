#ifndef YAMADA_SCENE_H_
#define YAMADA_SCENE_H_

#include "../Scene/Scene.h"

class World;

class yamadaScene:public Scene
{
public:
	// �R���X�g���N�^    
	yamadaScene(const IGameManagerPtr& gameManager);
	// ���̃V�[����Ԃ�
	virtual SceneName Next() const override;
	// �I��
	virtual void End() override;

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
};
#endif // !YAMADA_SCENE_H_
