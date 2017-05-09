#ifndef ISCENE_H_
#define ISCENE_H_

enum class SceneName;

//�V�[�����ۃC���^�[�t�F�C�X
class IScene
{
public:
	// ���z�f�X�g���N�^     
	virtual ~IScene() {}
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
};



#endif