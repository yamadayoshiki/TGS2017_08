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
	void Change(unsigned int num);
	//�`���`�̎擾
	GSrect* GetCurrentRect();

private:
	//�e�N�X�`����`
	GSrect m_TexRect;
	//�؂����`�̉���
	float m_CutWidth;
	//�e�N�X�`���ύX�Ԋu(�t���[��)
	unsigned int m_AnimationUpdateTimer;
	//�؂����`
	GSrect m_CutRect;
	//�؂���ԍ�(0���ڂ��琔����)
	int m_CurrentNum;
	//�A�j���[�V�����^�C�}�[
	unsigned int m_AnimationTimer;
};

#endif // !ANIMATION_H_
