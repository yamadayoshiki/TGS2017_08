#ifndef SCENE_H_
#define SCENE_H_

#include "../IScene.h"
#include "../../Base/GameManagerContains/IGameManagerPtr.h"
#include "../../StagingContains/TransitionStaging/TransitionPtr.h"

class World;

using WorldPtr = std::shared_ptr<World>;

//�V�[���C���^�[�t�F�C�X
class Scene :public IScene, public std::enable_shared_from_this<Scene>
{
public:
	enum class CarsorMovement
	{
		Up = 0,		//��
		Down,		//��
		Right,		//�E
		Left,		//��
	};
public:
	//�f�t�H���g�R���X�g���N�^
	Scene();
	//�R���X�g���N�^
	explicit Scene(const IGameManagerPtr& gameManager);
	// ���z�f�X�g���N�^     
	virtual ~Scene();

public:
	// �Z�b�g�A�b�v
	virtual void SetUp()override {}
	// �J�n     
	virtual void Start() override;
	// �X�V     
	virtual void Update(float deltaTime) override;
	// �`��     
	virtual void Draw() const override;
	// �I��     
	virtual void End() override;
	// �I�����Ă��邩�H     
	virtual bool IsEnd() const override;
	// ���̃V�[����Ԃ�     
	virtual SceneName Next() const override;
	// ���O��ݒ�
	void SetName(const SceneName & name) override;
	// ���O�̎擾
	SceneName GetName() override;
	// �q�̐ݒ�
	void SetUpChild(ChildScene& child) override;
	// ���b�Z�[�W����
	virtual void HandleMessage(EventMessage message, void* param)override;

	void StopWorld() override;
	void Restart() override;

protected:
	// �e��ŗL�̊J�n     
	virtual void OnStart() {}
	// �e��ŗL�̍X�V     
	virtual void OnUpdate(float deltaTime) {}
	// �e��ŗL�̕`��     
	virtual void OnDraw()const {}
	// �e��ŗL�̏I��     
	virtual void OnEnd() {}

protected:
	bool m_IsEnd;					//�I���t���O
	IGameManagerPtr p_GameManager;	//�Q�[���}�l�[�W���[
	WorldPtr p_World;				//���[���h
	SceneName m_SceneName;			//�V�[���̖��O
	TransitionPtr m_Transition;		//�J�ډ��o
	CarsorMovement					//�J�[�\���ړ�
		m_CarsorMovement{
		CarsorMovement::Up };
	int MapOrder = 0;				//�}�b�v�̏���
	bool isGameClear;				//�Q�[�����N���A������

private:
	bool PauseFlag = false;			//�|�[�Y�t���O
};

#endif // !SCENE_H_
