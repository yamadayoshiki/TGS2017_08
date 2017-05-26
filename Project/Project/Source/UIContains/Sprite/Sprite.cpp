#include "Sprite.h"

#include "../../FileReader/CsvReader.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"

Sprite::Sprite(IWorld * world, const IGameManagerPtr & gameManager, const GSvector2& position, const ITexturePtr & texture) :
	UI_Base(world, ActorName::UI_Sprite, position, gameManager, texture) {
	texture->Initialize();

	texture->GetParameter()->SetPosition(position);
}

void Sprite::onUpdate(float deltaTime){
	p_Texture->Update(deltaTime);
}

void Sprite::onDraw() const{
	p_Texture->Draw();
}

