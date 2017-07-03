#ifndef GAMETITLE_H_
#define GAMETITLE_H_

#include "../Scene/Scene.h"
#include"../../TextureContains/AnimationTexture/AnimationTexture.h"
//�^�C�g���V�[��
class GameTitle : public Scene
{
public:
	// �R���X�g���N�^    
	GameTitle(const IGameManagerPtr& gameManager);
	//�f�X�g���N�^
	~GameTitle();
	//�e�N�X�`���E�A�j���[�V�����̖��O�̐ݒ�
	void setName_TitleAnimation(const std::string& name);
	//�A�j���[�V�����̃��[�v�񐔂��擾
	unsigned int GetLoopTitleCount();

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	// �`��     
	virtual void OnDraw()const;
	//�I��
	virtual void End()override;

private:
	//�^�C�g���̏����ʒu
	float TitleSpeed = -600;
	//�^�C�g���̓���
	void TitleMove();
	//�����_���[
	Renderer2DPtr			p_Renderer;
	//�A�j���[�V�����e�N�X�`��
	AnimationTexture* p_AnimationTexture;
	//�A�j���[�V����
	Animation*				m_Animation;
	//�t���[����
	float					m_TitleFraemConter;
	//���O
	std::string				m_TitleName,m_TitleName2;
};

#endif