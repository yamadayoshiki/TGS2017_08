#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Base/Texture_Base.h"
class GameManager;

class Texture :public Texture_Base
{
public:
	//�R���X�g���N�^
	Texture(
		std::string texName,
		IGameManagerPtr gameManager);
	//������
	virtual void Initialize() override;
	//�X�V
	virtual void Update(float deltaTime) override;
	//�`��
	virtual void Draw() override;
	//�I��
	virtual void Finalize() override;
};

#endif // !TEXTURE_H_
