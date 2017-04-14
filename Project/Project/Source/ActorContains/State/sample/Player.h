#pragma once

#include "../../Base/Actor.h"
#include "../../../World/IWorld.h"
#include "../../../Math/Vector3.h"
#include "State/PlayerStateMgr.h"

// �v���[���[
class Player : public Actor {
public:
	// �R���X�g���N�^
	Player(IWorld* world, const Vector3& position);
	// �f�X�g���N�^
	~Player();
	// �X�V����
	virtual void onUpdate(float deltaTime) override;
	// �`�揈��
	virtual void onDraw() const override;
	// �Փ˔���
	virtual void onCollide(Actor& other) override;
private:
	// ��ԊǗ�
	PlayerStateMgr* mStateMgr;
};
