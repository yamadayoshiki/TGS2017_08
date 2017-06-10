#include "Enemy09.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../ActorContains/Body/OrientedBoundingBox.h"
//Map
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"

Enemy09::Enemy09(
	IWorld * world, 
	const GSvector2 & position, 
	const FourDirection front, 
	const IGameManagerPtr & gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_09,
		position,
		front,
		10,
		MapType::Double,
		gameManager,
		std::make_shared<Texture>("Enemy02", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f))) {
}

Enemy09::~Enemy09()
{
}

ActorPtr Enemy09::CsvGenerate(const int x, const int y, const int csvparam)
{
	GSvector2 position = p_World->GetMap()->CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<Enemy09>(p_World, position, dir, p_GameManager);
}

void Enemy09::SetUpCommand()
{
}

void Enemy09::SetUpState()
{
}

void Enemy09::onDraw() const
{
}

