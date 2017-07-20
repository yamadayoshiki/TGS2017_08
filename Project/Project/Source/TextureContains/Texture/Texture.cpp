#include "Texture.h"
#include "../../DrawManager/DrawManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
Texture::Texture(
	const std::string & texName,
	const DrawManagerSPtr & drawManager,
	const DrawOrder drawOrder)
	: Texture_Base(texName, drawManager, drawOrder) {
}

void Texture::ChangeTexture(const std::string & texName, const DrawOrder drawOrder){
	p_DrawManager.lock()->Remove(m_DrawOrderID);
	m_TexName = texName;
	m_DrawOrderID = p_DrawManager.lock()->Register(m_TexName, p_Parameter,drawOrder);
}

ITexturePtr Texture::Clone(const DrawOrder drawOrder) {
	std::shared_ptr<Texture> result = std::make_shared<Texture>(m_TexName, p_DrawManager.lock(), drawOrder);
	result->p_Parameter->Copy(p_Parameter);
	result->m_StopFlag = m_StopFlag;
	return result;
}
