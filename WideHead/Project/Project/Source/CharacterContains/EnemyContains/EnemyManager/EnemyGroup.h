#ifndef ENEMYGROUP_H_
#define ENEMYGROUP_H_
#include "../../../ActorContains/Actor/Actor.h"
#include <memory>
class EnemyManager;
//�G�l�~�[�O���[�v
class EnemyGroup : public Actor
{
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyGroup();

public:
	//�Z�b�g�A�b�v
	void SetUp(const std::shared_ptr<EnemyManager>& enemyMgr);
	//�q���폜����(���񂾎q�̍폜)
	void removeChildren_dead() override;

private:
	std::weak_ptr<EnemyManager> p_EnemyMgr;
};
#endif // !ENEMYGROUP_H_
