#include "Combo.h"

#include "../../FileReader/CsvReader.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../Selector/Selector.h"
#include "../../WorldContains/EventMessage/EventMessage.h"
#include "../../SceneContains/SceneName.h"
#include"../../Utility/Animation/Animation.h"
#include"../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../TextureContains/Texture/Texture.h"
#include <algorithm>

Combo::Combo(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name)
	:UI_Base(world, ActorName::UI_Combo, position, gameManager){
	p_Renderer2D = gameManager->GetRenderer2D();
	regist(file_name);
}

void Combo::regist(const std::string & file_name)
{
	CsvReader csv = CsvReader(file_name);

	//for (int row = 1; row < csv.rows(); row++) {
	//	Texture2DParameter param;
	//	param.SetPosition(GSvector2(csv.getf(row, 1), csv.getf(row, 2)));
	//	m_TextureList.push_back(std::make_shared<Texture>(csv.get(row, 0), p_Renderer2D));
	//}
}

void Combo::onUpdate(float deltaTime)
{
	//m_TextureList[1]->GetParameter()->SetScale({weidth,1.0f});
}

void Combo::onDraw() const
{
	//m_TextureList[0]->Draw();
	//m_TextureList[1]->Draw();
	//m_TextureList[2]->Draw();
}
void Combo::setTexture()
{

}
