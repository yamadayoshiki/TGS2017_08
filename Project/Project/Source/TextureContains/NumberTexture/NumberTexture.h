//#ifndef NUMBERTEXTURE_H_
//#define NUMBERTEXTURE_H_
//#include "../ITexture.h"
//#include <iostream>
//#include <GSvector2.h>
//#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
//#include "../../DrawManager/DrawManagerPtr.h"
//#include "../../DrawManager/DrawOrder.h"
//#include <vector>
////����ʒu
//enum class AlignType {
//	Right,	//�E����
//	Left,	//������
//};
//
///*
//����񓯂���{0,1,2,3,4,5,6,7,8,9}�̃e�N�X�`���z��
//*/
////�ԍ�Texture
//class NumberTexture : public ITexture
//{
//public:
//	NumberTexture(
//		const std::string& texName,			//�e�N�X�`���o�^��
//		const DrawManagerSPtr& drawManager,	//�`��Ǘ�
//		const DrawOrder drawOrder,			//�`�揇��
//		const AlignType type,				//����ʒu
//		const int length = 0);				//����(�f�t�H���g�̏ꍇ�\���������̂ݕ\��)
//	~NumberTexture();
//
//public:
//	//������
//	void Initialize()override;
//	//�X�V
//	void Update(float deltaTime) override;
//	//�p�����[�^�[�̎擾
//	Texture2DParameterSPtr GetParameter()override { return nullptr; }
//	//���[�v�񐔂̎擾
//	int GetLoopCount()override { return 0; }
//	//�ԍ��ݒ�
//	void SetNumber(int num);
//	//���W�ݒ�
//	void SetPos(const GSvector2& pos);
//	//���W+��]�̐ݒ�
//	void SetPosAndAngle(const GSvector2& pos, float angle)override;
//
//private:
//	//�ԍ��ݒ�(�\�������ݒ肠��)
//	void SetNumber(int num);
//	//�ԍ��ݒ�(�\�������ݒ�Ȃ�)
//	void SetNumber(int num);
//
//protected:
//	std::string m_TexName;				//�o�^��
//	int m_CutWidth;						//1�����̕�
//	AlignType m_Type;					//����ʒu
//	int m_Length;						//�\������
//	std::vector<Texture2DParameterSPtr>	//�p�����[�^�[�z��
//		p_ParamVector;
//	int m_DrawOrderID;					//�`�揇��ID
//	DrawManagerWPtr p_DrawManager;		//�`��Ǘ�
//};
//#endif // !NUMBERTEXTURE_H_
