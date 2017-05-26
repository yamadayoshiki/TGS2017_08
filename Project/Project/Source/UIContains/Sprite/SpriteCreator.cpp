#include "SpriteCreator.h"

#include "Sprite.h"
#include "../../FileReader/CsvReader.h"
#include "../../TextureContains/Base/Texture_Base.h"
#include "../../Utility/Animation/Animation.h"
#include "../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"

SpriteCreator::SpriteCreator(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name) :
	Actor(world, ActorName::UI_Sprite, position, gameManager) {
	regist(file_name);
}

void SpriteCreator::regist(const std::string & file_name)
{
	CsvReader csv = CsvReader(file_name);

	// çsÇÃÉãÅ[Év
	for (int row = 1; row < csv.rows(); row++) {
		std::string name = "Resource/Texture/UI/" + csv.get(row, 0);
		p_GameManager->GetRenderer2D()->LoadTexture(name, name);
		if (csv.geti(row, 1) == 0) {
			auto texture = std::make_shared<Texture_Base>(name, p_GameManager->GetRenderer2D());
			auto sprite = std::make_shared<Sprite>(p_World, p_GameManager, GSvector2(csv.getf(row, 4), csv.getf(row, 5)), texture);

			addChild(sprite);
		}
		else {
			auto texture = std::make_shared<AnimationTexture>(name, p_GameManager->GetRenderer2D(), new Animation(*p_GameManager->GetRenderer2D()->GetTextureRect(name), csv.geti(row, 2), 60.0f));
			auto sprite = std::make_shared<Sprite>(p_World, p_GameManager, GSvector2(csv.getf(row, 4), csv.getf(row, 5)), texture);

			addChild(sprite);
		}
	}
}

