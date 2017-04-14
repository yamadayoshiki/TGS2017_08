#ifndef NULLSCENE_H_ 
#define NULLSCENE_H_ 

#include "../Scene/Scene.h" 

// ��̃V�[�� 
class NullScene : public Scene
{
public:
	// �R���X�g���N�^    
	NullScene();
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