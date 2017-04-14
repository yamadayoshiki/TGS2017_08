#ifndef SCENE_H_
#define SCENE_H_

#include "../IScene.h"
#include "../../Base/GameManagerContains/IGameManager.h"

//�V�[���C���^�[�t�F�C�X
class Scene :public IScene
{
public:
	//�R���X�g���N�^
	Scene(IGameManager* gameManager);
	//�f�t�H���g�R���X�g���N�^
	Scene();
	// ���z�f�X�g���N�^     
	virtual ~Scene() {}
	// �J�n     
	virtual void Start() override;
	// �X�V     
	virtual void Update(float deltaTime) override;
	// �I�����Ă��邩�H     
	virtual bool IsEnd() const override;
	
public:
	// �`��     
	virtual void Draw() const override = 0;
	// ���̃V�[����Ԃ�     
	virtual SceneName Next() const override = 0;
	// �I��     
	virtual void End() override = 0;

protected:
	// �J�n     
	virtual void OnStart() = 0;
	// �X�V     
	virtual void OnUpdate(float deltaTime) = 0;

protected:
	bool m_IsEnd;					//�I���t���O
	IGameManager* p_GameManager;	//�Q�[���}�l�[�W���[
};

#endif // !SCENE_H_
