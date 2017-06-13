#include"BreakWall.h"
#include "../CharacterContains/EnemyContains/PlayerWatch/PlayerWatch.h"
#include "../WorldContains/IWorld.h"
#include "../Map/Map.h"
#include"../Map/MapType.h"
#include"../CharacterContains/EnemyContains/Entity/Enemys/Base/EnemyBase.h"
#include"../Define/Def_Nakayama.h"

//�R���X�g���N�^
#include"../ActorContains/ActorName.h"
#include"../TextureContains/Texture/Texture.h"
#include"../ActorContains/Body/OrientedBoundingBox.h"
//�`��
#include"../Base/GameManagerContains/IGameManager.h"
#include"../Utility/Rederer2D/Renderer2D.h"
//Command
#include"../Utility/FourDirection/FourDirection.h"
//CommandContains
#include"../CharacterContains/EnemyContains/CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include"../CharacterContains/EnemyContains/CommandContains/Commands/EnemyCommandName.h"
#include"../CharacterContains/EnemyContains/CommandContains/Commands/Null/EnemyCommandNull.h"
//State
#include "../CharacterContains/EnemyContains/StateContains/StateManager/EnemyStateManager.h"
#include "../CharacterContains/EnemyContains/StateContains/States/MoveContains/Standard/Idle/EnemyStateIdleStandard.h"
#include "../CharacterContains/EnemyContains/StateContains/States/CaughtContains/Standard/EnemyStateCaughtStandard.h"
#include "../CharacterContains/EnemyContains/StateContains/States/CrushContains/Standard/EnemyStateCrushStandard.h"
#include "../CharacterContains/EnemyContains/StateContains/States/DeadContaint/Standard/EnemyStateDeadStandard.h"
#include "../CharacterContains/EnemyContains/StateContains/States/DeadWall/DeadWall.h"
#include "../CharacterContains/EnemyContains/StateContains/States/Stop/EnemyStateStop.h"

BreakWall::BreakWall(
	IWorld * world,
	const GSvector2 & position,
	const IGameManagerPtr & gameManager)
	: EnemyBase(
		world,
		ActorName::BreakWall,
		position,
		FourDirection(),
		3,
		MapType::Default,
		gameManager,
		std::make_shared<Texture>("Block5", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2{ 0.0f, 0.0f }, 0.0f, GSvector2{ 1.0f, 1.0f }))
{
}

//������
void BreakWall::initialize() {
	//�v���C���[�Ď�
	p_PlayerWatch.reset(new PlayerWatch(shared_from_this()));
	//�e��ŗL�̃R�}���h�̐ݒ�
	SetUpCommand();
	//�e��ŗL��State�̐ݒ�
	SetUpState();
}

void BreakWall::SetUpCommand()
{
	//����
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//�ǉ�
	p_CommandManager->AddDic(EnemyCommandName::None, std::make_shared<EnemyCommandNull>(shared_from_this()));
	//����Command�ݒ�
	p_CommandManager->Change(EnemyCommandName::None);
}

void BreakWall::SetUpState()
{
	//����
	p_StateManager.reset(new EnemyStateManager());
	//State�ǉ�
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaughtStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrushStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDeadStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStop>(shared_from_this(), 120));
	//����State�ݒ�
	p_StateManager->change(EnemyStateName::Idle);
}

void BreakWall::onDraw() const
{
	// �u���b�N�폜���ɌĂ�
	/*if (gsGetKeyState(GKEY_A)) {
		getWorld()->GetMap().DeleteChip(getPosition(), p_World);
	}*/


	Texture2DParameter param;
	param.SetPosition(getBody()->position());
	param.SetCenter({ 16.0f, 16.0f });
	param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("Block5"));
	param.SetScale({ 1.0f , 1.0f });
	param.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_GameManager->GetRenderer2D()->DrawTexture("Block5", param);
}

//csv�Ő���(�g�p���p�����override)
ActorPtr BreakWall::CsvGenerate(const int x, const int y, const int csvparam) {
	GSvector2 pos = getWorld()->GetMap()->CsvPosCnvVector2(x, y, m_MapType);
	pos = pos - GSvector2(CHIP_SIZE / 2, CHIP_SIZE / 2);
	return std::make_shared<BreakWall>(p_World, pos, p_GameManager);
}