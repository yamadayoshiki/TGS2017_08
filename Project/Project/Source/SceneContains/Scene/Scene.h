#ifndef SCENE_H_
#define SCENE_H_

#include "../IScene.h"
#include "../../Base/GameManagerContains/IGameManagerPtr.h"
#include "../../StagingContains/TransitionStaging/TransitionPtr.h"

class World;

using WorldPtr = std::shared_ptr<World>;

//�V�[���C���^�[�t�F�C�X
class Scene :public IScene
{
public:
	//�R���X�g���N�^
	Scene(const IGameManagerPtr& gameManager,const WorldPtr& world);
	// ���z�f�X�g���N�^     
	virtual ~Scene();
	// �J�n     
	virtual void Start() override;
	// �X�V     
	virtual void Update(float deltaTime) override;
	// �`��     
	virtual void Draw() const override;
	// �I�����Ă��邩�H     
	virtual bool IsEnd() const override;

public:
	// ���̃V�[����Ԃ�     
	virtual SceneName Next() const override = 0;
	// �I��     
	virtual void End() override = 0;
	// ���O��ݒ�
	virtual void SetName(const SceneName & name) override;

protected:
	// �e��ŗL�̊J�n     
	virtual void OnStart() = 0;
	// �e��ŗL�̍X�V     
	virtual void OnUpdate(float deltaTime) = 0;

protected:
	bool m_IsEnd;					//�I���t���O
	IGameManagerPtr p_GameManager;	//�Q�[���}�l�[�W���[
	WorldPtr p_World;
	//���[���h
	// �V�[���̖��O
	SceneName m_SceneName;
	// �J�ډ��o
	TransitionPtr m_Transition;

};

#endif // !SCENE_H_
