#ifndef TEXTURE_BASE_H_
#define TEXTURE_BASE_H_

#include "../ITexture.h"
#include <iostream>

#include "../../Utility/Rederer2D/Renderer2DPtr.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"

class Texture_Base :public ITexture
{
public:
	//�R���X�g���N�^
	Texture_Base(
		const std::string& texName,
		Renderer2DPtr renderer);
	//�f�t�H���g�R���X�g���N�^
	Texture_Base();
	//���z�f�X�g���N�^
	virtual ~Texture_Base() {
		Finalize();
	}
	//������
	virtual void Initialize() override;
	//�X�V
	virtual void Update(float deltaTime) override;
	//�`��
	virtual void Draw() override;
	//�I��
	void Finalize() override;
	//�p�����[�^�[�̎擾
	virtual Texture2DParameter* GetParameter() override;
	//�R�s�[�֎~
	Texture_Base(const Texture_Base& other) = delete;
	Texture_Base& operator = (const Texture_Base& other) = delete;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() {}
	//�e��ŗL�̏I������
	virtual void OnFinalize() {}

protected:
	std::string m_TexName;				//�o�^��
	Renderer2DPtr p_Renderer;			//�����_���[
	Texture2DParameter* p_Parameter;	//�p�����[�^�[
};

#endif // !TEXTURE_BASE_H_
