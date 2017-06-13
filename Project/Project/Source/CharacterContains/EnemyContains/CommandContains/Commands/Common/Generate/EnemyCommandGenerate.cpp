#include "EnemyCommandGenerate.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../Map/Map.h"
#include "../../../../../Factory/CharacterFactory.h"

//�R���X�g���N�^
EnemyCommandGenerate::EnemyCommandGenerate(
	const EnemyBasePtr & enemy,
	const float charaNumber,
	const float intervalTime)
	: EnemyCommandBase(enemy)
	, m_CharaNumber(charaNumber)
	, m_IntervalTime(intervalTime)
	, m_Timer(0) {
}

//�f�X�g���N�^
EnemyCommandGenerate::~EnemyCommandGenerate() {
}

//�e��ŗL�̏�����
void EnemyCommandGenerate::OnInitialize() {
	m_Timer = 0;
}

//�e��ŗL�̍X�V
void EnemyCommandGenerate::OnUpdate(float deltaTime) {
	m_Timer += deltaTime;
	if (m_Timer >= m_IntervalTime)
	{
		//���Ӄ^�C���̎擾
		std::unordered_map<FourDirection, TileData> aroundTile = p_Enemy.lock()->getWorld()->GetMap()->GetAroundTile(p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetMapType());
		//���ʃ^�C���̃f�[�^�̎擾
		TileData frontTile = aroundTile[p_Enemy.lock()->GetDirection()];
		//���ʂɐ���
		p_Enemy.lock()->addChild(p_Enemy.lock()->getWorld()->GetCharacterFactory()->GetGenerateCharacter(frontTile.Position(), m_CharaNumber * 10 + (int)p_Enemy.lock()->GetDirection().name));
	
		m_Timer = 0;
	}
}

