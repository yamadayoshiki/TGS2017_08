#include "Enemy08.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../ActorContains/Body/OrientedBoundingBox.h"
//Map
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"

Enemy08::Enemy08(IWorld * world, const GSvector2 & position, const FourDirection front, const IGameManagerPtr & gameManager)
	: EnemyBase(world,
		ActorName::Enemy_08,
		position,
		front,
		10,
		MapType::Double,
		gameManager,
		std::make_shared<Texture>("Enemy02", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f))) {
}

Enemy08::~Enemy08()
{
}

ActorPtr Enemy08::CsvGenerate(const int x, const int y, const int csvparam)
{
	GSvector2 position = p_World->GetMap()->CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<Enemy08>(p_World, position, dir, p_GameManager);
}

void Enemy08::SetUpCommand()
{
}

void Enemy08::SetUpState()
{
}

void Enemy08::onDraw() const
{
}