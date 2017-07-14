#ifndef GAMETITLE_H_
#define GAMETITLE_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include <iostream>
class AnimationTexture;
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
	virtual void OnEnd()override;

private:
	//�^�C�g���̓���
	void TitleMove();

private:
	float TitleSpeed = -600;					//�^�C�g���̏����ʒu
	float m_TitleFraemConter;					//�t���[����

	Texture2DParameterSPtr p_Title;				//�^�C�g���w�i
	Texture2DParameterSPtr p_WideHead;			//�^�C�g�����S
	Texture2DParameterSPtr p_Start;				//�X�^�[�g
	AnimationTexture* p_AnimationTexture;		//�A�j���[�V�����e�N�X�`��

	int m_TitleNum;
	int m_WideHeadNum;
	int m_StartNum;
};

#endif