#ifndef CREDIT_START_H_
#define CREDIT_STSRT_H_

#include"../../../WorldContains/IWorldPtr.h"
#include"../../../Base/GameManagerContains/IGameManagerPtr.h"
#include"../../IScene.h"
#include"../../../TextureContains/ITexturePtr.h"

class CreditStart :public IScene
{
public:
	//�R���X�g���N�^
	CreditStart(IWorld* world, const IGameManagerPtr& gameManager);

protected:
	// �Z�b�g�A�b�v
	virtual void SetUp() override {}
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

private:
	//���[���h
	IWorldPtr p_World;
	//�Q�[���}�l�[�W���[
	IGameManagerPtr p_GameManager;
	//�e�N�X�`��
	ITexturePtr p_Texture;
	//�^�C�}�[
	float timer_{ 0.0f };
	//�I���t���O
	bool is_End{ false };
};
#endif // !CREDIT_START_H_
