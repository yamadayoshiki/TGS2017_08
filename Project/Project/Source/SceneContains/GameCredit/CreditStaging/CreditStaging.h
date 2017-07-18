#ifndef CREDIT_STAGING_H_
#define CREDIT_STAGING_H_

#include"../../../WorldContains/IWorldPtr.h"
#include"../../../Base/GameManagerContains/IGameManagerPtr.h"
#include"../../IScene.h"
#include "../../../StagingContains/TransitionStaging/TransitionPtr.h"


class CreditStaging :public IScene
{
public:
	//�R���X�g���N�^
	CreditStaging(IWorld* world, const IGameManagerPtr& gameManager);

protected:
	// �Z�b�g�A�b�v
	virtual void SetUp()override {}
	// �J�n     
	virtual void Start();
	// �X�V     
	virtual void Update(float deltaTime);
	//�`��
	virtual void Draw()const;
	//�I��
	virtual void End();
	// �I�����Ă��邩�H     
	virtual bool IsEnd() const override;
	// ���̃V�[����Ԃ�     
	virtual SceneName Next() const override;
	// ���O�̐ݒ�
	virtual void SetName(const SceneName& name)override;
	// ���O�̎擾
	virtual SceneName GetName() override;
	// �q�̐ݒ�
	void SetUpChild(ChildScene& child)override {}
	// ���b�Z�[�W����
	virtual void HandleMessage(EventMessage message, void* param) override {}
	// ���[���h�̒�~
	virtual void StopWorld()override {}
	// ���[���h�̍ĊJ
	virtual void Restart()override {}
	// �Z��z��̐ݒ�
	virtual void SetBrothers(const std::vector<SceneName>& children) override {}

private:
	//���[���h
	IWorldPtr p_World;
	//�Q�[���}�l�[�W���[
	IGameManagerPtr p_GameManager;
	//�^�C�}�[
	float timer_{ 0.0f };
	//�I���t���O
	bool is_End{ false };
	TransitionPtr m_Transition;
};
#endif // !CREDIT_STAGING_H_
