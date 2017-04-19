#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Base/Texture_Base.h"
class GameManager;

class Texture :public Texture_Base
{
public:
	//�R���X�g���N�^
	Texture(
		const std::string& texName,
		Renderer2D* renderer);
	//�X�V
	virtual void Update(float deltaTime) override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̏I������
	virtual void OnFinalize() override {}
};

#endif // !TEXTURE_H_
