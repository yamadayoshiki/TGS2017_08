#include "Player.h"

#include "../../../ResourceLoader/ResourceLoader.h"
#include "../../../Math/Vector3.h"
#include "../../Body/BoundingCapsule.h"
#include "../../../Scene/Base/SceneData.h"
#include "../../../Define.h"
#include "State/PlayerState_Enum.h"

#include <memory>

// �R���X�g���N�^
Player::Player(IWorld * world, const Vector3 & position) :
	Actor(world, "Player", position, std::make_shared<BoundingCapsule>(Vector3::Up * PERSON_CENTER_HEIGHT, Matrix::Identity, PERSON_CENTER_HEIGHT, PERSON_RADIUS)),
	mStateMgr(new PlayerStateMgr(mPosition, mRotation)){

	// ���f���̓ǂݍ���
	mModelHandle = MV1DuplicateModel(ResourceLoader::GetInstance().getModelHandle(ModelID::PLAYER));
	mAnimation = Animation(mModelHandle);
	
	//������Ԃ𐳖ʂɐݒ�
	mRotation *= Matrix::CreateFromAxisAngle(mRotation.Up(), 180);
	mRotation.NormalizeRotationMatrix();

	// ����State�̎w��
	mStateMgr->change(*this, PlayerState_Enum::N_IDLE);
}

// �f�X�g���N�^
Player::~Player(){
	delete mStateMgr;
}

// �X�V����
void Player::onUpdate(float deltaTime) {
	// ��ԊǗ��̍X�V����
	mStateMgr->action(*this, deltaTime);

	// �A�j���[�V�����Đ�
	mAnimation.changeAnim(mMotionID, mMotionSpeed);
	mAnimation.update(deltaTime);

	// �n�`�Ƃ̏Փ˔���
	field();

	// �s������
	mPosition = Vector3::Clamp(mPosition, mWorld->getSceneData()->getCurData().status.mParams.pos_min, mWorld->getSceneData()->getCurData().status.mParams.pos_max);

	// �ϊ��s������f���ɑ��
	MV1SetMatrix(mModelHandle, Matrix::MatrixToMATRIX(getPose()));
}

// �`�揈��
void Player::onDraw() const{
	// �v���C���[���f���̕`��
	MV1DrawModel(mModelHandle);
	// �X�e�[�^�X�̕`��i���[�^�[�j
	mWorld->getSceneData()->getCurData().status.draw();
}

// �Փ˔���
void Player::onCollide(Actor & other){
	// ��Ԃ��Ƃ̏Փ˔���
	mStateMgr->collide(*this, other);
}


