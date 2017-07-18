#ifndef ISCENE_H_
#define ISCENE_H_

#include "SceneName.h"
enum class SceneMode;
class ChildScene;

//�V�[�����ۃC���^�[�t�F�C�X
class IScene
{
public:
	// ���z�f�X�g���N�^     
	virtual ~IScene() {}
	// �Z�b�g�A�b�v
	virtual void SetUp() = 0;
	// �J�n     
	virtual void Start() = 0;
	// �X�V     
	virtual void Update(float deltaTime) = 0;
	// �`��     
	virtual void Draw() const = 0;
	// �I�����Ă��邩�H     
	virtual bool IsEnd() const = 0;
	// ���̃V�[����Ԃ�     
	virtual SceneName Next() const = 0;
	// �I��     
	virtual void End() = 0;
	// ���O�̐ݒ�
	virtual void SetName(const SceneName& name) = 0;
	// ���O�̎擾
	virtual SceneName GetName() = 0;
	// �q�̐ݒ�
	virtual void SetUpChild(ChildScene& child) = 0;
};



#endif