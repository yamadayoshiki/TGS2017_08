#include "DrawManager.h"
#include "../Utility/Rederer2D/Renderer2D.h"
#include "../Utility/Texture2DParameter/Factory/Texture2DParamFactory.h"
#include "../Utility/Texture2DParameter/Texture2DParameter.h"
#include <iterator>
//�R���X�g���N�^
DrawManager::DrawManager(Renderer2DPtr renderer2D)
	:m_Oreder(0)
	, p_Renderer(renderer2D)
	, p_Texture2DParamFactory(std::make_unique<Texture2DParamFactory>(renderer2D)) {
	m_DrawOrderMap.clear();
	m_NonDisplayDrawOrderMap.clear();
}

//�f�X�g���N�^
DrawManager::~DrawManager() {
	Clear();
	p_Texture2DParamFactory.reset();
}

//�v�f�̍폜
void DrawManager::Clear() {
	m_DrawOrderMap.clear();
	m_NonDisplayDrawOrderMap.clear();
	m_Oreder = 0;
}

//�o�^(�f�t�H���g�ݒ�)
DrawOrderID DrawManager::RegisterDefaultParam(
	const std::string & texName,
	Texture2DParameterSPtr & param,
	const DrawOrder order) {
	param = std::make_shared<Texture2DParameter>();
	param->m_Rect = *p_Renderer->GetTextureRect(texName);
	param->m_Center = { param->m_Rect.right / 2,param->m_Rect.bottom / 2 };
	return Register(texName, param, order);
}

//�o�^
DrawOrderID DrawManager::Register(
	const std::string & texName,
	const Texture2DParameterSPtr & parameter,
	const DrawOrder order) {
	DrawOrderObject result;
	result.texName = texName;
	result.param = parameter;
	result.id = ((int)order) * 1000 + m_Oreder;
	m_Oreder++;
	m_DrawOrderMap[result.id] = result;
	if (result.id == 6048) 
	{
		int i = 0;
	}
	return result.id;
}

//�\�����[�h�ύX
void DrawManager::ChageDisplayMode(const DrawOrderID id, const DisplayMode mode) {
	switch (mode)
	{
	case DisplayMode::Display: {
		auto itr = m_NonDisplayDrawOrderMap.find(id);
		if (itr != m_NonDisplayDrawOrderMap.end() && m_DrawOrderMap.find(id) == m_DrawOrderMap.end()) {
			m_DrawOrderMap[id] = (*itr).second;
			m_NonDisplayDrawOrderMap.erase(id);
		}
	}
		break;
	case DisplayMode::NonDisplay: {
		auto itr = m_DrawOrderMap.find(id);
		if (itr != m_DrawOrderMap.end() && m_NonDisplayDrawOrderMap.find(id) == m_NonDisplayDrawOrderMap.end()) {
			m_NonDisplayDrawOrderMap[id] = (*itr).second;
			m_DrawOrderMap.erase(id);
		}
	}
		break;
	}
}

//�폜
void DrawManager::Remove(const DrawOrderID id) {
	m_DrawOrderMap.erase(id);
	m_NonDisplayDrawOrderMap.erase(id);
}

//�`��I�u�W�F�N�g�\���̂̎擾
DrawOrderObject DrawManager::GetDrawObject(const DrawOrderID id) {
	auto result = m_DrawOrderMap.find(id);
	if (result != m_DrawOrderMap.end())return (*result).second;
	result = m_NonDisplayDrawOrderMap.find(id);
	if (result != m_NonDisplayDrawOrderMap.end())return (*result).second;
	std::cout << "�����炸><";
	return DrawOrderObject();
}

//�`��
void DrawManager::Draw() {
	for (auto itr = m_DrawOrderMap.begin(); itr != m_DrawOrderMap.end(); itr++)
		p_Renderer->DrawTexture(itr->second.texName, itr->second.param.lock());
}

GSrect DrawManager::GetRect(const std::string & texName){
	return *p_Renderer->GetTextureRect(texName);
}

void DrawManager::ChangeOrder(const DrawOrderID id, const DrawOrder drawOrder){
	DrawOrderObject obj = GetDrawObject(id);
	Register(obj.texName, obj.param.lock(), drawOrder);
}