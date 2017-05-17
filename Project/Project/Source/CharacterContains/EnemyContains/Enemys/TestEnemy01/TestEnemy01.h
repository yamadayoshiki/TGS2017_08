#pragma once

#include "../Base/EnemyBase.h"
#include "../../CommandContains/Commands/Interface/IEnemyCommand.h"

class TestEnemy01 : public EnemyBase
{
public:
	//�R���X�g���N�^
	TestEnemy01(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager);
protected:
	//�X�V
	virtual void onUpdate(float deltaTime) override;
	//�`��
	virtual void onDraw() const override;
	//�Փ˂���
	virtual void onCollide(Actor& other) override;

protected:
	IEnemyCommand* command;		//�R�}���h
};