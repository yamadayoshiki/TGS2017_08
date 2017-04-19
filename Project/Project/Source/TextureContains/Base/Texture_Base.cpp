#include "Texture_Base.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"

//�R���X�g���N�^
Texture_Base::Texture_Base(
	const std::string& texName,
	Renderer2D* renderer)
	: m_TexName(texName)
	, p_Renderer(renderer)
	, p_Parameter(new Texture2DParameter()) {
}

//������
void Texture_Base::Initialize() {
	//�摜�T�C�Y�ʂ��Rect��ݒ�
	p_Parameter->SetRect(*(p_Renderer->GetTextureRect(m_TexName)));

	//�e��ŗL�̏�����
	OnInitialize();
}

//�`��
void Texture_Base::Draw() {
	p_Renderer->DrawTexture(m_TexName, *p_Parameter);
}

//�I������
void Texture_Base::Finalize() {
	delete p_Parameter;
	delete p_Renderer;
	OnFinalize();
}

//�p�����[�^�[�̎擾
Texture2DParameter* Texture_Base::GetParameter() {
	return p_Parameter;
}