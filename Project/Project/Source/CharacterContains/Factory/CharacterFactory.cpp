#include "CharacterFactory.h"
#include "../../ActorContains/ActorName.h"
#include "../../WorldContains/IWorld.h"
#include "../../Utility/TurnDirection/TurnDirection.h"
#include "../../Define/Def_GSvector2.h"
#include "../../Utility/MathSupport/MathSupport.h"

//�����L����
#include "../EnemyContains/Entity/Enemys/Enemy01/Enemy01.h"
#include "../EnemyContains/Entity/Enemys/Enemy02/Enemy02.h"
#include "../EnemyContains/Entity/Enemys/Enemy03/Enemy03.h"
#include "../EnemyContains/Entity/Enemys/Enemy04/Enemy04.h"
#include "../EnemyContains/Entity/Enemys/Enemy05/Enemy05.h"
#include "../EnemyContains/Entity/Enemys/Enemy06/Enemy06.h"
#include "../EnemyContains/Entity/Enemys/Enemy07/Enemy07.h"
#include "../EnemyContains/Entity/Enemys/Enemy08/Enemy08.h"
//#include "../EnemyContains/Entity/Enemys/"
//#include "../EnemyContains/Entity/Enemys/"
//#include "../EnemyContains/Entity/Enemys/"
#include "../../Wall/BreakWall.h"
#include "../PlayerContains/Player/Player.h"

//�R���X�g���N�^
CharacterFactory::CharacterFactory(
	const IWorldPtr& world,
	const IGameManagerPtr& gameManager)
	: p_IWorld(world)
	, p_IGameManager(gameManager) {
	//������o�^
	m_ParentMap[ActorName::EnemyManager] = p_IWorld.lock()->findActor(ActorName::EnemyManager);
	m_ParentMap[ActorName::PlayerManager] = p_IWorld.lock()->findActor(ActorName::PlayerManager);

	//�����L�����o�^
	m_GenerateMap[11] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy01>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };
	m_GenerateMap[12] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy02>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), FourDirection(FourDirectionName::Right), p_IGameManager.lock()) };
	m_GenerateMap[13] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy02>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), FourDirection(FourDirectionName::Left), p_IGameManager.lock()) };
	m_GenerateMap[14] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy02>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), FourDirection(FourDirectionName::Down), p_IGameManager.lock()) };
	m_GenerateMap[15] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy03>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), TurnDirection(TurnDirectionName::Clockwise), p_IGameManager.lock()) };
	m_GenerateMap[16] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy03>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), TurnDirection(TurnDirectionName::AntiClockwise), p_IGameManager.lock()) };
	m_GenerateMap[17] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy04>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };
	m_GenerateMap[18] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy05>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };

	//�u���b�N
	m_GenerateMap[81] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<BreakWall>(p_IWorld.lock().get(),GSVECTOR2_ZERO,p_IGameManager.lock()) };

	//�v���C���[
	m_GenerateMap[91] = ActorData{ m_ParentMap[ActorName::PlayerManager],std::make_unique<Player>(p_IWorld.lock().get(),GSVECTOR2_ZERO,p_IGameManager.lock()) };
}

//�f�X�g���N�^
CharacterFactory::~CharacterFactory() {
	m_ParentMap.clear();
	m_GenerateMap.clear();
}

//����
void CharacterFactory::Generate(const int x, const int y, const int csvData) {
	//�ŏ�ʂQ�����L�����L�[�ɕϊ�
	int key = MathSupport::GetCutNum(csvData, 1, 2);
	if (key == 0) return;
	//�ŏ�ʂQ���̔r��
	int csvParam = csvData % (int)std::pow(10, MathSupport::GetDigit(csvData) - 2);

	ActorData& data = m_GenerateMap[key];
	data.parent.lock()->addChild(data.child->CsvGenerate(x, y, csvParam));
}