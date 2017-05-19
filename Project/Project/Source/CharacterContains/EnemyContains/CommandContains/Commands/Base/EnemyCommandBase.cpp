#include "EnemyCommandBase.h"
#include "../../../../../Define/Def_GSvector2.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../ActorContains/Body/Base/Body.h"
#include "../../../../../Map/Map.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Define/Def_Nakayama.h"

//�R���X�g���N�^
EnemyCommandBase::EnemyCommandBase(const EnemyBasePtr& enemy)
	: IEnemyCommand()
	, p_Enemy(enemy)
	, m_Velocity(GSVECTOR2_ZERO)
	, m_RotateAngle(0.0f)
	, m_NextCommand(EnemyCommandName::None)
	, m_IsEnd(false) {
}

//������
void EnemyCommandBase::Initialize() {
	m_NextCommand = EnemyCommandName::None;
	m_IsEnd = false;
	//�e��ŗL�̏�����
	OnInitialize();
}

//�X�V
void EnemyCommandBase::Update(float deltaTime) {
	//�e��ŗL�̍X�V
	OnUpdate(deltaTime);
}

//�ڕW�n�_�܂ł̈ړ��x�N�g���̎擾
GSvector2 EnemyCommandBase::GetVelocity() const {
	return m_Velocity;
}

//��]�p�x�̎擾
float EnemyCommandBase::GetRotateAngle() const {
	return m_RotateAngle;
}

//�I���`�F�b�N
bool EnemyCommandBase::IsEnd() {
	return m_IsEnd;
}

//���R�}���h�̎擾
EnemyCommandName EnemyCommandBase::GetNextCommand() const {
	return m_NextCommand;
}

//���߃X�e�[�g
EnemyStateName EnemyCommandBase::GetCurrentStateName() const {
	return EnemyStateName::None;
}

//���R�}���h�̐ݒ�
void EnemyCommandBase::Change(EnemyCommandName next) {
	m_NextCommand = next;
	m_IsEnd = true;
}

//�w�����,���g����̃}�b�v�z��
std::vector<int> EnemyCommandBase::GetFrontMapData(const FourDirectionName fourDirectionName, MapType type) {
	//�G�l�~�[�{�̂̍��W
	GSvector2 pos = p_Enemy->getPosition();
	//�G�l�~�[�{�̂̌���
	FourDirection dir = FourDirection(fourDirectionName);
	//�}�b�v
	Map& map = p_Enemy->getWorld()->GetMap();
	//����+�w�ʂ̃}�X��
	int backChipNum;

	//���ʐi�s�����̔z��̍쐬
	std::vector<int> result;
	switch (dir.name)
	{
	case FourDirectionName::Up:
		//�c��Map�z��
		result = map.GetRow(pos, type);
		//�t���ɐ���
		std::reverse(begin(result), end(result));
		//�������܂߂Ȃ��ォ��̃}�X��
		backChipNum = pos.y / (CHIP_SIZE* ((int)type + 1));
		//�������܂߂��w�ʂ̃}�X��
		backChipNum = map.GetHeight(type) - backChipNum;
		break;

	case FourDirectionName::Down:
		//�c��Map�z��
		result = map.GetRow(pos, type);
		//�������܂߂��ォ��̃}�X��
		backChipNum = pos.y / (CHIP_SIZE* ((int)type + 1)) + 1;
		break;

	case FourDirectionName::Left:
		//����Map�z��
		result = map.GetColumn(pos, type);
		//�t���ɐ���
		std::reverse(begin(result), end(result));
		//�������܂߂Ȃ�������̃}�X��
		backChipNum = pos.x / (CHIP_SIZE* ((int)type + 1));
		//�������܂߂��w�ʂ̃}�X��
		backChipNum = map.GetWidth(type) - backChipNum;
		break;

	case FourDirectionName::Right:
		//����Map�z��
		result = map.GetColumn(pos, type);
		//�������܂߂�������̃}�X��
		backChipNum = pos.x / (CHIP_SIZE* ((int)type + 1)) + 1;
		break;

	default:
		break;
	}

	//�w�ʃ}�X�̍폜
	for (int i = 0; i < result.size(); i++)
	{
		if (backChipNum > i)
			result.erase(result.begin());

		else
			break;
	}

	return result;
}
