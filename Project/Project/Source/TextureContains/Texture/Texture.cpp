#include "Texture.h"
#include "../../DrawManager/DrawManager.h"

Texture::Texture(
	const std::string & texName,
	const DrawManagerSPtr & drawManager,
	const DrawOrder drawOrder)
	: Texture_Base(texName, drawManager, drawOrder) {
}

void Texture::ChangeTexture(const std::string & texName, const DrawOrder drawOrder){
	p_DrawManager.lock()->Remove(m_DrawOrderID);

	m_DrawOrderID = p_DrawManager.lock()->Register(m_TexName, p_Parameter,drawOrder);
}
