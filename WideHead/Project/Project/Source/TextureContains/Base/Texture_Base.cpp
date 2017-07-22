#include "Texture_Base.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../DrawManager/DrawManager.h"
//�R���X�g���N�^
Texture_Base::Texture_Base(
	const std::string & texName,
	const DrawManagerSPtr& drawManager,
	const DrawOrder drawOrder)
	: m_TexName(texName)
	, p_DrawManager(drawManager)
	, m_StopFlag(false) {
	//�`��Ǘ��ɓo�^
	m_DrawOrderID = p_DrawManager.lock()->RegisterDefaultParam(m_TexName, p_Parameter, drawOrder);
}

//�f�X�g���N�^
Texture_Base::~Texture_Base() {
	//�`��Ǘ�����폜
	p_DrawManager.lock()->Remove(m_DrawOrderID);
}

//�p�����[�^�[�̎擾
Texture2DParameterSPtr Texture_Base::GetParameter() {
	return p_Parameter;
}

void Texture_Base::Initialize() {
	Restart();
	OnInitialize();
}

void Texture_Base::Update(float deltaTime) {
	if (m_StopFlag == true)	return;

	OnUpdate(deltaTime);
}

void Texture_Base::Stop() {
	m_StopFlag = true;
}

void Texture_Base::Restart() {
	m_StopFlag = false;
}

void Texture_Base::SetPosAndAngle(const GSvector2 & pos, float angle) {
	p_Parameter->m_Position = pos;
	p_Parameter->m_Rotate = angle;
}

void Texture_Base::ChangeDisplayMode(const DisplayMode mode) {
	p_DrawManager.lock()->ChageDisplayMode(m_DrawOrderID, mode);
}

void Texture_Base::ChangeDrawOredr(const DrawOrder drawOrder) {
	p_DrawManager.lock()->Remove(m_DrawOrderID);
	m_DrawOrderID = p_DrawManager.lock()->Register(m_TexName, p_Parameter, drawOrder);
}