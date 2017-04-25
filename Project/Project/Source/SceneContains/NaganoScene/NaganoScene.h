#ifndef NAGANO_SCENE_H_
#define NAGANO_SCENE_H_

#include "../Scene/Scene.h"
#include <memory>

class World;

//�Q�[����
class NaganoScene : public Scene
{
public:
	// �R���X�g���N�^    
	NaganoScene(const IGameManagerPtr& gameManager, const WorldPtr& world);
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

private:
	using WorldPtr = std::shared_ptr<World>;
	WorldPtr p_World;
};

#endif