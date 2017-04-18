#ifndef TEXTURE_BASE_H_
#define TEXTURE_BASE_H_

#include "../ITexture.h"
#include <iostream>

#include "../../Base/GameManagerContains/IGameManagerPtr.h"

class Texture2DParameter;

class Texture_Base :public ITexture
{
public:
	//�R���X�g���N�^
	Texture_Base(
		std::string texName,
		IGameManagerPtr gameManager);
	//������
	virtual void Initialize() = 0;
	//�X�V
	virtual void Update(float deltaTime) = 0;
	//�`��
	virtual void Draw() = 0;
	//�I��
	virtual void Finalize() = 0;

protected:
	unsigned int m_TexID;
	IGameManagerPtr p_GameManager;
	Texture2DParameter* p_Parameter;
};

#endif // !TEXTURE_BASE_H_
