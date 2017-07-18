#ifndef numbertexture_h_
#define numbertexture_h_
#include "../itexture.h"
#include <iostream>
#include <gsvector2.h>
#include "../../utility/texture2dparameter/texture2dparameterptr.h"
#include "../../drawmanager/drawmanagerptr.h"
#include "../../drawmanager/draworder.h"
#include <vector>
#include <GStype.h>

struct Texture2DParamAndID {
	Texture2DParameterSPtr m_TexParam;
	int m_DrawOrderID;
};

/*
����񓯂���{0,1,2,3,4,5,6,7,8,9}�̃e�N�X�`���z��
�E����/���W�͉E����w��
*/
//�ԍ�texture
class NumberTexture : public ITexture
{
public:
	NumberTexture(
		const std::string& texName,			//�e�N�X�`���o�^��
		const DrawManagerSPtr& drawManager,	//�`��Ǘ�
		const DrawOrder drawOrder,			//�`�揇��
		const GSvector2& pos,				//�E����W
		const int length = 0);				//����(�f�t�H���g�̏ꍇ�\���������̂ݕ\��)
	~NumberTexture();

public:
	//������
	void Initialize()override;
	//�X�V
	void Update(float deltatime) override {}
	//�p�����[�^�[�̎擾
	Texture2DParameterSPtr GetParameter()override { return nullptr; }
	//���[�v�񐔂̎擾
	int GetLoopCount()override { return 0; }
	//�X�g�b�v
	void Stop()override {}
	//���X�^�[�g
	void Restart()override {}
	//���W+��]�̐ݒ�
	void SetPosAndAngle(const GSvector2& pos, float angle)override {};
	//�\�����[�h�ؑ�
	void ChangeDisplayMode(const DisplayMode mode)override;

public:
	//�ԍ��ݒ�
	void SetNumber(int num);
	//���W�ݒ�
	void SetPos(const GSvector2& pos);

private:
	//�ԍ��ݒ�(�\�������ݒ肠��)
	void SetNumberLocal(int num);
	//�ԍ��ݒ�(�\�������ݒ�Ȃ�)
	void SetNumberLocalNonZero(int num);
	//�w�萔���̐؂����`���擾
	GSrect GetNumToRect(int num);
	//�\�����̐؂�ւ�
	void ChangeLength(const int length);
	//�w�茅�̍��W�̎擾
	GSvector2 GetOneDigitPos(
		const int numDigit,		//����
		const GSvector2& pos);	//���W

protected:
	std::string m_TexName;				//�o�^��
	DrawManagerWPtr p_DrawManager;		//�`��Ǘ�
	DrawOrder m_DrawOrder;				//�`�揇��
	GSvector2 m_Position;				//�E����W
	float m_Length;						//�\������
	std::vector<Texture2DParamAndID>	//�p�����[�^�[�z��
		m_ParamVector;
	int m_CutHeight;					//�c��
	int m_CutWidth;						//1�����̂Ɖ���
	int m_Number;						//����

};
#endif // !numbertexture_h_
