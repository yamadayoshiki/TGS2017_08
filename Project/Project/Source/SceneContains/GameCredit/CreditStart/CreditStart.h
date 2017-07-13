#ifndef CREDIT_START_H_
#define CREDIT_STSRT_H_

#include"../../../WorldContains/IWorldPtr.h"
#include"../../../Base/GameManagerContains/IGameManagerPtr.h"
#include"../../IScene.h"

class CreditStart :public IScene
{
public:
	//�R���X�g���N�^
	CreditStart(IWorld* world, const IGameManagerPtr& gameManager);

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
	//�I���t���O
	bool is_End{ false };
};
#endif // !CREDIT_START_H_
