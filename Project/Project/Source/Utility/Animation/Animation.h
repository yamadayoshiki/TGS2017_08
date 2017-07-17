#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <gslib.h>

class Animation
{
public:
	//�R���X�g���N�^
	Animation(
		const GSrect& texRect,
		const float cutWidth,
		const unsigned int animmationUpdateTimer);

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

private:
	GSrect m_TexRect;						//�e�N�X�`����`
	float m_CutWidth;						//�؂����`�̉���
	unsigned int m_AnimationUpdateTimer;	//�e�N�X�`���ύX�Ԋu(�t���[��)
	GSrect m_CutRect;						//�؂����`
	int m_CurrentNum;						//�؂���ԍ�("0"���ڂ��琔����)
	unsigned int m_AnimationTimer;			//�A�j���[�V�����^�C�}�[
	unsigned int m_LoopCount;				//���[�v��
};

#endif // !ANIMATION_H_
