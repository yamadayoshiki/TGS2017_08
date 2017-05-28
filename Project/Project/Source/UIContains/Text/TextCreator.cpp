#include "TextCreator.h"

#include "Text.h"
#include "../../FileReader/CsvReader.h"
#include "../../TextureContains/Base/Texture_Base.h"
#include "../../Utility/Animation/Animation.h"
#include "../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"

// �R���X�g���N�^
TextCreator::TextCreator(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name) :
	Actor(world, ActorName::UI_Text, position, gameManager) {
	// ����
	create(file_name);
}

// ����
void TextCreator::create(const std::string & file_name)
{

}

