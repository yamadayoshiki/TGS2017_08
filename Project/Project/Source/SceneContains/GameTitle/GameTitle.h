#ifndef GAMETITLE_H_
#define GAMETITLE_H_

#include "../Scene/Scene.h"

//�^�C�g���V�[��
class GameTitle : public Scene
{
public:
	// �R���X�g���N�^    
	GameTitle(const IGameManagerPtr& gameManager, const WorldPtr& world);
	
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