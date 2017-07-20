#include"PlayerState_Damage.h"
#include"../../../../../ActorContains/ActorGroup.h"
#include"../../../../NeutralContains/Explosion/Neutral_Explosion.h"
#include "../../../../../SceneContains/SceneManager/SceneManager.h"
//コンストラクタ
PlayerState_Damage::PlayerState_Damage(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//各状態独自の初期化
void PlayerState_Damage::unique_init()
{
	gsPlaySE(SE_PLAYER_EXPLOSION);
	p_Player.lock()->getWorld()->addActor(ActorGroup::Effect, std::make_shared<Neutral_Explosion>(p_Player.lock()->getWorld(), p_Player.lock()->getPosition(), p_GameManager));
	if (p_GameManager->GetSceneManager()->GetSceneName() != SceneName::GameTutorial)
		m_Parameter.m_Remaining -= 1;
}
//更新処理
void PlayerState_Damage::update(float deltaTaime)
{
	if (m_Parameter.m_Remaining < 0) {
		change(PlayerStateName::Dead);
		return;
	}
	change(PlayerStateName::Respawn);
}

//終了処理
void PlayerState_Damage::end() {}
//入力処理
void PlayerState_Damage::input() {}