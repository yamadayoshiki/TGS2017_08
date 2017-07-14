#ifndef TEXTURE2DPARAMFACTORY_H_
#define TEXTURE2DPARAMFACTORY_H_
#include <iostream>
#include "../Texture2DParameterPtr.h"
#include "../../Rederer2D/Renderer2DPtr.h"
//2D�e�N�X�`���H��
class Texture2DParamFactory
{
public:
	//�R���X�g���N�^
	Texture2DParamFactory(const Renderer2DPtr& renderer);
	//�f�X�g���N�^
	~Texture2DParamFactory();
	//�p�����[�^�̎擾
	Texture2DParameter* GetDefaultTexture2DParam(
		const std::string texName);

private:
	Renderer2DPtr p_Renderer;	//�����_���[
};
#endif // !TEXTURE2DPARAMFACTORY_H_