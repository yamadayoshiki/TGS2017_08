#include "DrawOrderManager.h"
#include "../Utility/Rederer2D/Renderer2D.h"

DrawOrderManager::DrawOrderManager(Renderer2DPtr renderer2D)
	:m_Oreder(0)
	, p_Renderer(renderer2D) {
	m_DrawOrderSet.clear();
}

DrawOrderManager::~DrawOrderManager() {
	Clear();
}

void DrawOrderManager::Clear() {
	m_DrawOrderSet.clear();
	m_Oreder = 0;
}

DrawOrderID DrawOrderManager::Register(
	const std::string & texName,
	const Texture2DParameterPtr & parameter,
	const DrawOrder order)
{
	DrawOrderObject result;

	result.texName = texName;
	result.param = parameter;
	result.id = ((int)order) * 1000 + m_Oreder;
	m_Oreder++;

	return result.id;
}

void DrawOrderManager::Remove(const DrawOrderID id) {
	m_DrawOrderSet.erase(id);
}

DrawOrderObject DrawOrderManager::GetDrawObject(const DrawOrderID id) {
	return m_DrawOrderSet[id];
}


void DrawOrderManager::Draw() {
	for (auto itr = m_DrawOrderSet.begin(); itr != m_DrawOrderSet.end(); itr++)
	{
		p_Renderer->DrawTexture(itr->second.texName, itr->second.param.lock());
	}
}
