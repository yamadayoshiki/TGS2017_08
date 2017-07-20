#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <gslib.h>
#include "AnimationPtr.h"
class Animation
{
public:
	//�R���X�g���N�^
	Animation(
		const GSrect& texRect,
		const float cutWidth,
		const float animmationUpdateTimer);

	//�f�t�H���g�R���X�g���N�^
	Animation();
	//�f�X�g���N�^
	~Animation();
	//������
	void Initialize();
	//�X�V
	void Update(float deltaTime);
	//�`���`�ύX
	void Change();
	//�`���`�̎擾
	GSrect* GetCurrentRect();
	//���[�v�񐔂̎擾
	unsigned int GetLoopCount();
	//�N���[������
	AnimationSPtr Clone();
	//�؂����`�̉����̎擾
	float GetCutWidth() const;

private:
	GSrect m_TexRect;						//�e�N�X�`����`
	float m_CutWidth;						//�؂����`�̉���
	float m_AnimationUpdateTimer;			//�e�N�X�`���ύX�Ԋu(�t���[��)
	GSrect m_CutRect;						//�؂����`
	int m_CurrentNum;						//�؂���ԍ�("0"���ڂ��琔����)
	float m_AnimationTimer;					//�A�j���[�V�����^�C�}�[
	unsigned int m_LoopCount;				//���[�v��
};

#endif // !ANIMATION_H_
