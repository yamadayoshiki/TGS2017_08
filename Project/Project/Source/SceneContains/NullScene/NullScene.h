#ifndef NULLSCENE_H_ 
#define NULLSCENE_H_ 

#include "../Scene/Scene.h" 

// ��̃V�[�� 
class NullScene : public Scene
{
public:
	// �f�t�H���g�R���X�g���N�^
	NullScene();
	//�R���X�g���N�^
	NullScene(const IGameManagerPtr& gameManager);
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
	// �I��     
	virtual void OnEnd();
};

#endif