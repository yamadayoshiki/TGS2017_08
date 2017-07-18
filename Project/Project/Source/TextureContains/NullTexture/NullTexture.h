#ifndef NULLTEXTURE_H_
#define NULLTEXTURE_H_
#include "../ITexture.h"
//��̎���
class NullTexture :public ITexture
{
public:
	//�f�t�H���g�R���X�g���N�^
	NullTexture() {}
	//������
	void Initialize() override {}
	//�X�V
	void Update(float deltaTime) override {}
	//�p�����[�^�[�̎擾
	Texture2DParameterSPtr GetParameter() override { return nullptr; }
	//���[�v�񐔂̎擾
	int GetLoopCount() override { return 0; }
	//�X�g�b�v
	void Stop()override {}
	//���X�^�[�g
	void Restart()override {}
	//���W+��]�̐ݒ�
	void SetPosAndAngle(const GSvector2& pos, float angle)override {};
	//�\�����[�h�ؑ�
	void ChangeDisplayMode(const DisplayMode mode)override {}
};
#endif // !NULLTEXTURE_H_