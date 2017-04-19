#ifndef TEXTURE_BASE_H_
#define TEXTURE_BASE_H_

#include "../ITexture.h"
#include <iostream>

#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"

class Texture_Base :public ITexture
{
public:
	//�R���X�g���N�^
	Texture_Base(
		const std::string& texName,
		Renderer2D* renderer);
	//���z�f�X�g���N�^
	virtual ~Texture_Base() {
		Finalize();
	}
	//������
	virtual void Initialize() override;
	//�X�V
	virtual void Update(float deltaTime) override = 0;
	//�`��
	virtual void Draw() override;
	//�I��
	virtual void Finalize() override;
	//�p�����[�^�[�̎擾
	Texture2DParameter* GetParameter();

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() {}
	//�e��ŗL�̏I������
	virtual void OnFinalize() {}

protected:
	std::string m_TexName;				//�o�^��
	Renderer2D* p_Renderer;				//�����_���[
	Texture2DParameter* p_Parameter;	//�p�����[�^�[
};

#endif // !TEXTURE_BASE_H_
