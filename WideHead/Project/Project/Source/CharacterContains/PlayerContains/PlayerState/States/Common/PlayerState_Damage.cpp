#include"PlayerState_Damage.h"
#include"../../../../../ActorContains/ActorGroup.h"
#include"../../../../NeutralContains/Explosion/Neutral_Explosion.h"
#include "../../../../../SceneContains/SceneManager/SceneManager.h"
//�R���X�g���N�^
PlayerState_Damage::PlayerState_Damage(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Damage::unique_init()
{
	gsPlaySE(SE_PLAYER_EXPLOSION);
	p_Player.lock()->getWorld()->addActor(ActorGroup::Effect, std::make_shared<Neutral_Explosion>(p_Player.lock()->getWorld(), p_Player.lock()->getPosition(), p_GameManager));
	if (p_GameManager->GetSceneManager()->GetSceneName() != SceneName::GameTutorial)
		m_Parameter.m_Remaining -= 1;
}
//�X�V����
void PlayerState_Damage::update(float deltaTaime)
{
	if (m_Parameter.m_Remaining < 0) {
		change(PlayerStateName::Dead);
		return;
	}
	change(PlayerStateName::Respawn);
}

//�I������
void PlayerState_Damage::end() {}
//���͏���
void PlayerState_Damage::input() {}