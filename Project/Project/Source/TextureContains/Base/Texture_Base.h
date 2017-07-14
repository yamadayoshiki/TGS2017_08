#ifndef TEXTURE_BASE_H_
#define TEXTURE_BASE_H_
#include <iostream>
#include "../ITexture.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include "../../DrawManager/DrawManagerPtr.h"
#include "../../DrawManager/DrawOrder.h"

class Texture_Base :public ITexture
{
public:
	//�R���X�g���N�^
	Texture_Base(
		const std::string& texName,
		const DrawManagerSPtr& drawManager,
		const DrawOrder drawOrder);
	//�f�X�g���N�^
	~Texture_Base();
	//�p�����[�^�[�̎擾
	Texture2DParameterSPtr GetParameter() override;
	//�R�s�[�֎~
	Texture_Base(const Texture_Base& other) = delete;
	Texture_Base& operator = (const Texture_Base& other) = delete;

public:
	//������
	virtual void Initialize() override {}
	//�X�V
	virtual void Update(float deltaTime) override {}
	//���[�v�񐔂̎擾
	virtual int GetLoopCount() override = 0;
	//���W+��]�̐ݒ�
	void SetPosAndAngle(const GSvector2& pos, float angle)override;
	//�\�����[�h�ؑ�
	void ChangeDisplayMode(const DisplayMode mode)override;

protected:
	std::string m_TexName;				//�o�^��
	Texture2DParameterSPtr p_Parameter;	//�p�����[�^�[
	int m_DrawOrderID;					//�`�揇��ID
	DrawManagerWPtr p_DrawManager;		//�`��Ǘ�
};

#endif // !TEXTURE_BASE_H_
