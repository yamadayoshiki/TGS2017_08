#include "ResultStart.h"

#include "../../../WorldContains/World/World.h"
#include"../../../ActorContains/ActorGroup.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../Utility/Sound/SoundName.h"
#include"../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include"../../../TextureContains/Texture/Texture.h"
#include "../../../DrawManager/DisplayMode.h"
#include "../../../DrawManager/DrawManager.h"

#include<GSeasing.h>

ResultStart::ResultStart(IWorld* world,const IGameManagerPtr & gameManager)
	:p_World(world),p_GameManager(gameManager),
	p_Texture(std::make_shared<Texture>("BigBlock", p_GameManager->GetDrawManager(), DrawOrder::BackGround))
{
	//�p�����[�^�̐ݒ�
	p_Texture->GetParameter()->m_Position = GSvector2(550, 300);
	p_Texture->GetParameter()->m_Center = { 0.0f,0.0f };
	p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
}



// �J�n     
void ResultStart::Start()
{
	is_End = false;
	p_Texture->ChangeDisplayMode(DisplayMode::Display);
}
// �X�V     
void ResultStart::Update(float deltaTime)
{
	if (m_Timer >= 60 * 2)
	{
		is_End = true;
	}

	m_Timer += deltaTime;
}
//�`��
void ResultStart::Draw()const
{

}
//�I��
void ResultStart::End(){
	p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
}

// �I�����Ă��邩�H     
bool ResultStart::IsEnd() const
{
	return is_End;
}

SceneName ResultStart::Next() const {
	return SceneName::ResultStaging;
}
void ResultStart::SetName(const SceneName & name) {
	
}

SceneName ResultStart::GetName() {
	return SceneName::ResultStart;
}