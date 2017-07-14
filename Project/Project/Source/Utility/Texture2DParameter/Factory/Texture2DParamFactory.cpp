#include "Texture2DParamFactory.h"
#include "../Texture2DParameter.h"
#include "../../Rederer2D/Renderer2D.h"

Texture2DParamFactory::Texture2DParamFactory(const Renderer2DPtr& renderer)
{
}

Texture2DParamFactory::~Texture2DParamFactory()
{
}

Texture2DParameter* Texture2DParamFactory::GetDefaultTexture2DParam(const std::string texName) {
	Texture2DParameter* result = new Texture2DParameter();
	result->m_Rect = *p_Renderer->GetTextureRect(texName);
	return result;
}