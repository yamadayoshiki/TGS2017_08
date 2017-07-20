#ifndef ITEXTURE_H_
#define ITEXTURE_H_
#include "../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include "../DrawManager/DisplayMode.h"
#include "ITexturePtr.h"
struct GSvector2;
enum class DrawOrder;
class ITexture
{
public:
	//���z�f�X�g���N�^
	virtual ~ITexture() {}
	//������
	virtual void Initialize() = 0;
	//�X�V
	virtual void Update(float deltaTime) = 0;
	//�p�����[�^�[�̎擾
	virtual Texture2DParameterSPtr GetParameter() = 0;
	//���[�v�񐔂̎擾
	virtual int GetLoopCount() = 0;
	//�X�g�b�v
	virtual void Stop() = 0;
	//���X�^�[�g
	virtual void Restart() = 0;
	//���W+��]�̐ݒ�
	virtual void SetPosAndAngle(const GSvector2& pos, float angle) = 0;
	//�\�����[�h�ؑ�
	virtual void ChangeDisplayMode(const DisplayMode mode) = 0;
	//�`�揇���ؑ�
	virtual void ChangeDrawOredr(const DrawOrder drawOrder) = 0;
	//�N���[������
	virtual ITexturePtr Clone(const DrawOrder drawOrder) = 0;

};

#endif // !ITEXTURE_H_
