#include "Sprite.h"

#include "../../FileReader/CsvReader.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"

Sprite::Sprite(IWorld * world, const IGameManagerPtr & gameManager, const GSvector2& position, const ITexturePtr & texture) :
	UI_Base(world, ActorName::UI_Sprite, position, gameManager, texture) {

}

void Sprite::regist(const std::string & file_name){
}


void Sprite::onUpdate(float deltaTime)
{
}

void Sprite::onDraw() const
{
}

void Sprite::onMessage(EventMessage message, void * param)
{
}
