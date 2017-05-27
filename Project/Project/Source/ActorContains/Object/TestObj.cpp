#include "TestObj.h"
#include "../Body/OrientedBoundingBox.h"
#include "../../Map/Map.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../Define/Def_Nakayama.h"

TestObj::TestObj(IWorld* world, const GSvector2 & position, const IGameManagerPtr& gameManager)
	: Actor(
		world,
		ActorName::Enemy,
		position,
		gameManager,
		std::make_shared<NullTexture>(),
		std::make_shared<OrientedBoundingBox>(GSvector2{ 0.0f, 0.0f }, 0.0f, GSvector2{ 1.0f, 1.0f })) {

	angle = 0.0f;

	p_GameManager->GetRenderer2D()->LoadTexture("Block5", "Resource/StreamingAssets/Block5.png");
}

void TestObj::onUpdate(float deltaTime)
{

	if (gsGetKeyState(GKEY_LEFT) == GS_TRUE) {
		m_Transform.m_Position.x -= 1.0f;
	}
	if (gsGetKeyState(GKEY_RIGHT) == GS_TRUE) {
		m_Transform.m_Position.x += 1.0f;
	}
	if (gsGetKeyState(GKEY_UP) == GS_TRUE) {
		m_Transform.m_Position.y -= 1.0f;
	}
	if (gsGetKeyState(GKEY_DOWN) == GS_TRUE) {
		m_Transform.m_Position.y += 1.0f;
	}

	if (gsGetKeyState(GKEY_A) == GS_TRUE) {
		angle += 1.0f;
	}
	if (gsGetKeyState(GKEY_D) == GS_TRUE) {
		angle -= 1.0f;
	}

	m_Transform.m_Angle = angle;
}

void TestObj::onDraw() const
{
	glDisable(GL_LIGHTING);
	Actor::onDraw();
	glColor3f(1.0f, 1.0f, 1.0f);
	Texture2DParameter tposition;
	tposition.SetPosition(m_Transform.m_Position);
	tposition.SetCenter({ CHIP_SIZE / 2, CHIP_SIZE / 2 });
	tposition.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("Block5"));
	tposition.SetScale({ 1.0f , 1.0f });
	tposition.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_GameManager->GetRenderer2D()->DrawTexture("Block5", tposition);
	
}

void TestObj::onCollide(Actor &)
{
	glColor3f(1.0f, 0.0f, 0.0f);
}

void TestObj::onMessage(EventMessage event, void *)
{
}

ActorPtr TestObj::clone(const GSvector2 & position, const FourDirection& front)
{
	return std::make_shared<TestObj>(p_World, position, p_GameManager);
}
