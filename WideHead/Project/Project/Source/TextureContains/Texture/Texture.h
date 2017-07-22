#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Base/Texture_Base.h"

class Texture :public Texture_Base
{
public:
	//�R���X�g���N�^
	Texture(
		const std::string& texName,
		const DrawManagerSPtr& drawManager,
		const DrawOrder drawOrder);
	//���[�v�񐔂̎擾
	int GetLoopCount() override { return 0; }
	//�N���[������
	virtual ITexturePtr Clone(const DrawOrder drawOrder) override;

public:
	//�e�N�X�`������
	void ChangeTexture(const std::string& texName, const DrawOrder drawOrder);
};

#endif // !TEXTURE_H_