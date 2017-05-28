#include "UI_Base.h"

#include "../../StagingContains/TransitionStaging/Transition/Transition.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"

UI_Base::UI_Base(IWorld* world, const ActorName& name, const GSvector2 & position, const IGameManagerPtr& gameManager, const ITexturePtr& texture):
	Actor(world, name, position, gameManager, texture){
	//m_Transition.addTransition(std::make_shared<Transition>(new Texture2DParameter()));
}

UI_Base::~UI_Base(){
	//p_GameManager->GetRenderer2D()->DeleteTexture(p_Texture->GetParameter);
}

void UI_Base::onUpdate(float deltaTime){

}

void UI_Base::onDraw() const{

}

void UI_Base::onCollide(Actor &){

}

void UI_Base::onMessage(EventMessage event, void *){

}

