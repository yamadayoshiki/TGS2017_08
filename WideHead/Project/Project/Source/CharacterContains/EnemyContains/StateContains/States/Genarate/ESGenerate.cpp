#include "ESGenerate.h"
#include <GSmusic.h>
#include "../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../Factory/CharacterFactory.h"
#include "../../../../../Map/Map.h"
#include "../../../../../TextureContains/ITexture.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"
ESGenerate::ESGenerate(
	const EnemyBasePtr & enemy,
	const SoundName se,
	const float forwardDis,
	const int charaNum,
	const int lagTime)
	: EnemyStateBase(enemy)
	, m_SE(se)
	, m_ForwardDis(forwardDis)
	, m_CharaNumber(charaNum)
	, m_LagTime(lagTime)
	, m_Timer(0) {
}

void ESGenerate::unique_init() {
	m_Timer = 0;
	//テクスチャ切替
	p_Enemy.lock()->Settexture("Generate");
}

void ESGenerate::update(float deltaTime) {
	if (m_LagTime == m_Timer)
		Generate();

	if (p_Enemy.lock()->getTexture()->GetLoopCount() >= 1)
		change(EnemyStateName::Idle);

	m_Timer++;
}

void ESGenerate::end() {
	//テクスチャ切替
	p_Enemy.lock()->Settexture("Normal");
}

void ESGenerate::Generate() {
	//SE
	gsPlaySE(m_SE);
	//周辺タイルの取得
	std::unordered_map<FourDirection, TileData> aroundTile = p_Enemy.lock()->getWorld()->GetMap()->GetAroundTile(p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetMapType());
	//正面タイルのデータの取得
	TileData frontTile = aroundTile[p_Enemy.lock()->GetDirection()];
	//正面に生成
	p_Enemy.lock()->addChild(p_Enemy.lock()->getWorld()->GetCharacterFactory()->GetGenerateCharacter(frontTile.Position(), m_CharaNumber * 10 + (int)p_Enemy.lock()->GetDirection().name));
}
