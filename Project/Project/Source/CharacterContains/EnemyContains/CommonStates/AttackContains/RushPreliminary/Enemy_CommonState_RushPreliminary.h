#ifndef ENEMY_COMMONSTATE_RUSHPRELIMINARY_H_
#define ENEMY_COMMONSTATE_RUSHPRELIMINARY_H_

#include "../AttackBase/Enemy_CommonState_AttackBase.h"

class Enemy_CommonState_RushPreliminary :public Enemy_CommonState_AttackBase
{
public:
	//�R���X�g���N�^
	Enemy_CommonState_RushPreliminary(GSvector2& pos, GSmatrix4& mat);
protected:
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor & actor) override;
	// �X�V����
	virtual void onUpdate(Actor & actor, float deltaTime) override;
	// �Փ˔���
	virtual void onCollide(const Actor & other) override;
	// �I�����̏���
	virtual void onEnd() override;
	// ���͏���
	virtual void onInput() override;
};
#endif // !ENEMY_COMMONSTATE_RUSHPRELIMINARY_H_
