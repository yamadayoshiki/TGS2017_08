#include "Texture_Base.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"

//コンストラクタ
Texture_Base::Texture_Base(
	std::string texName,
	IGameManagerPtr gameManager)
	: p_GameManager(gameManager)
	, p_Parameter(new Texture2DParameter())
{
	m_TexID 
		= p_GameManager->GetRenderer2D()->GetTextureID(texName);
}