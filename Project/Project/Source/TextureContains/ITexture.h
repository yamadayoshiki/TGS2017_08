#ifndef ITEXTURE_H_
#define ITEXTURE_H_

class ITexture
{
public:
	//���z�f�X�g���N�^
	virtual ~ITexture() {
		Finalize();
	}
	//������
	virtual void Initialize() = 0;
	//�X�V
	virtual void Update(float deltaTime) = 0;
	//�`��
	virtual void Draw() = 0;
	//�I��
	virtual void Finalize() = 0;
};

#endif // !ITEXTURE_H_
