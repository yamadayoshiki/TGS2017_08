#ifndef NULLSCENE_H_ 
#define NULLSCENE_H_ 

#include "../IScene.h"

// ��̃V�[�� 
class NullScene : public IScene
{
public:
	// �f�t�H���g�R���X�g���N�^
	NullScene() {}
	// �Z�b�g�A�b�v
	virtual void SetUp()override {}
	// �J�n     
	void Start() override {}
	// �X�V     
	void Update(float deltaTime)override {}
	// �`��     
	void Draw() const override {}
	// �I�����Ă��邩�H     
	bool IsEnd() const override { return false; }
	// ���̃V�[����Ԃ�     
	SceneName Next() const override { return SceneName::None; }
	// �I��     
	void End()override {}
	// ���O�̐ݒ�
	void SetName(const SceneName& name) override {}
	// ���O�̎擾
	SceneName GetName() override { return SceneName::None; }
	// �q�̐ݒ�
	void SetUpChild(ChildScene& child)override {}
	// ���b�Z�[�W����
	virtual void HandleMessage(EventMessage message, void* param) override {}
	// ���[���h�̒�~
	virtual void StopWorld()override {}
	// ���[���h�̍ĊJ
	virtual void Restart()override {}
	// �Z��z��̐ݒ�
	virtual void SetBrothers(const std::vector<SceneName>& children)override {}
};

#endif