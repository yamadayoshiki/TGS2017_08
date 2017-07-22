#include "BodyFactory.h"
#include "../NullBody/NullBody.h"
#include "../Base/BodyBase.h"
#include "../Elements/Primitive/AABB2D/AABB2D.h"
#include "../Elements/Primitive/AASegment2D/AASegment2D.h"
#include "../Elements/Collidable/BodyCollidable.h"
Body::BodyFactory::BodyFactory() {
	m_GenerateMap.clear();
	Register();
}

Body::BodyFactory::~BodyFactory() {
	m_GenerateMap.clear();
}

Body::IBodyPtr Body::BodyFactory::Generate(const MotionType type, const BodyDataName name) {
	if (type == MotionType::None || name == BodyDataName::None)
		return std::make_shared<NullBody>();

	return m_GenerateMap[name]->Clone(type);
}

void Body::BodyFactory::Transform(IBodyPtr & body, const BodyDataName name) {
	body->Transform(m_GenerateMap[name]->GetBodyCollidable());
}

void Body::BodyFactory::Register() {
	//一辺32の正方形
	m_GenerateMap[BodyDataName::AABB_32] = std::make_unique<BodyBase>();
	m_GenerateMap[BodyDataName::AABB_32]->AddShape(std::make_shared<AABB2D>(GSvector2(0.0f, 0.0f), GSvector2(16.0f, 16.0f)), { 0.0f,0.0f }, 0.0f);
	m_GenerateMap[BodyDataName::AABB_32]->SetAABB({ 16.0f, 16.0f });
	//プレイヤーアーム(攻撃範囲)
	m_GenerateMap[BodyDataName::PlayerAttackRange] = std::make_unique<BodyBase>();
	m_GenerateMap[BodyDataName::PlayerAttackRange]->AddShape(std::make_shared<AABB2D>(GSvector2(0.0f, 0.0f), GSvector2(16.0f, 32.0f)), { 16.0f,0.0f }, 0.0f);
	m_GenerateMap[BodyDataName::PlayerAttackRange]->SetAABB({ 32.0f,32.0f });
	//プレイヤー
	m_GenerateMap[BodyDataName::Player_Open] = std::make_unique<BodyBase>();
	m_GenerateMap[BodyDataName::Player_Open]->AddShape(std::make_shared<AABB2D>(GSvector2(0.0f, 0.0f), GSvector2(16.0f, 32.0f)), { -16.0f,0.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Open]->AddShape(std::make_shared<AASegment2D>(GSvector2(0.0f, 0.0f), GSvector2(0.0f, 8.0f)), { 32.0f,-32.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Open]->AddShape(std::make_shared<AASegment2D>(GSvector2(0.0f, 0.0f), GSvector2(0.0f, 8.0f)), { 32.0f,24.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Open]->AddShape(std::make_shared<AASegment2D>(GSvector2(0.0f, 0.0f), GSvector2(0.0f, 48.0f)), { 0.0f,-24.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Open]->SetAABB({ 32.0f,32.0f });
	//閉じているとき
	m_GenerateMap[BodyDataName::Player_Close] = std::make_unique<BodyBase>();
	m_GenerateMap[BodyDataName::Player_Close]->AddShape(std::make_shared<AABB2D>(GSvector2(0.0f, 0.0f), GSvector2(16.0f, 32.0f)), { -16.0f,0.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Close]->AddShape(std::make_shared<AASegment2D>(GSvector2(0.0f, 0.0f), GSvector2(0.0f, 8.0f)), { 32.0f,-8.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Close]->AddShape(std::make_shared<AASegment2D>(GSvector2(0.0f, 0.0f), GSvector2(0.0f, 8.0f)), { 32.0f,0.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Close]->AddShape(std::make_shared<AASegment2D>(GSvector2(0.0f, 0.0f), GSvector2(0.0f, 16.0f)), { 0.0f,-8.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Close]->SetAABB({ 32.0f,32.0f });
	//挟んでいるとき
	m_GenerateMap[BodyDataName::Player_Clip] = std::make_unique<BodyBase>();
	m_GenerateMap[BodyDataName::Player_Clip]->AddShape(std::make_shared<AABB2D>(GSvector2(0.0f, 0.0f), GSvector2(16.0f, 32.0f)), { -16.0f,0.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Clip]->AddShape(std::make_shared<AASegment2D>(GSvector2(0.0f, 0.0f), GSvector2(0.0f, 8.0f)), { 32.0f,-26.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Clip]->AddShape(std::make_shared<AASegment2D>(GSvector2(0.0f, 0.0f), GSvector2(0.0f, 8.0f)), { 32.0f,18.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Clip]->AddShape(std::make_shared<AASegment2D>(GSvector2(0.0f, 0.0f), GSvector2(0.0f, 32.0f)), { 0.0f,-16.0f }, 0.0f);
	m_GenerateMap[BodyDataName::Player_Clip]->SetAABB({ 32.0f,32.0f });
}