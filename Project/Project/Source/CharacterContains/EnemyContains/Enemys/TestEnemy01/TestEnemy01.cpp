#include "TestEnemy01.h"
#include "../../../../ActorContains/ActorName.h"
#include "../../../../TextureContains/Texture/Texture.h"
#include "../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../CommandContains/Commands/Straight/EnemyCommandStraight.h"

//コンストラクタ
TestEnemy01::TestEnemy01(
	IWorld* world,
	const GSvector2& position,
	const IGameManagerPtr& gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_01,
		position,
		1.0f,
		gameManager,
		std::make_shared<Texture>("Enemy01", gameManager->GetRenderer2D()))
	, command(new EnemyCommandStraight(std::enable_shared_from_this<EnemyBase>::shared_from_this(), FourDirection(FourDirectionName::Right))) {
	command->Initialize();
}
//更新
void TestEnemy01::onUpdate(float deltaTime) {
	command->Update(deltaTime);

	p_StateManager->action(deltaTime);
}

//描画
void TestEnemy01::onDraw() const {
	p_Body->transform(getTransform())->draw();

	Texture2DParameter param;
	param.SetPosition(m_Transform.m_Position);
	param.SetCenter({ 32.0f, 32.0f });
	param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("Enemy01"));
	param.SetScale({ 1.0f , 1.0f });
	param.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_GameManager->GetRenderer2D()->DrawTexture("Enemy01", param);
}
//衝突した
void TestEnemy01::onCollide(Actor& other) {

}