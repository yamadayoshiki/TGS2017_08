#ifndef CREDIT_END_H_
#define CREDIT_END_H_

#include"../../../WorldContains/IWorldPtr.h"
#include"../../../Base/GameManagerContains/IGameManagerPtr.h"
#include"../../IScene.h"
#include"../../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include"../../../StagingContains/TransitionStaging/TransitionPtr.h"
#include <GStype.h>

class CreditEnd :public IScene
{
public:
public:
	//�R���X�g���N�^
	CreditEnd(IWorld* world, const IGameManagerPtr& gameManager);

protected:
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

private:
	//���[���h
	IWorldPtr p_World;
	//�Q�[���}�l�[�W���[
	IGameManagerPtr p_GameManager;
	//�^�C�}�[
	float timer_{ 0.0f };
	//�ő厞��
	float maxTimer_{ 60.0f };
	//�I���t���O
	bool is_End{ false };
	//�J�ډ��o
	TransitionPtr p_Transition;
	//
	Texture2DParameterSPtr p_Param;
	//
	GScolor m_Color{ 1.0f,1.0f,1.0f,1.0f };
	//
	int MapOrder;

	int m_Score{ 0 };

};
#endif // !CREDIT_END_H_
