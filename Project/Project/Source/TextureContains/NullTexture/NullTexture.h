#ifndef NULLTEXTURE_H_
#define NULLTEXTURE_H_

#include "../Base/Texture_Base.h"

class NullTexture :public Texture_Base
{
public:
	//�R���X�g���N�^
	NullTexture(
		const std::string& texName,
		Renderer2DPtr renderer)
		:Texture_Base(texName, renderer) {}
	//�f�t�H���g�R���X�g���N�^
	NullTexture() :Texture_Base() {}
	//�X�V
	virtual void Update(float deltaTime) override {}

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override {}
	//�e��ŗL�̏I������
	virtual void OnFinalize() override {}
};

#endif // !NULLTEXTURE_H_
