#ifndef NAKAYAMA_SCENE_H_
#define NAKAYAMA_SCENE_H_

#include "../Scene/Scene.h"
#include <memory>

class World;

//�Q�[����
class NakayamaScene : public Scene
{
public:
	// �R���X�g���N�^    
	NakayamaScene(const IGameManagerPtr& gameManager, const WorldPtr& world);
	// �`��     
	virtual void Draw() const override;
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

#endif