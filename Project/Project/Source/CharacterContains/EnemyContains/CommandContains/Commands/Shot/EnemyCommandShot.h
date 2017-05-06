#ifndef ENEMYCOMMANDSHOT_H_
#define ENEMYCOMMANDSHOT_H_

#include "../Base/EnemyCommandBase.h"

class EnemyCommandShot : public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandShot(const EnemyBasePtr& enemy);
	//�X�V
	virtual void Update(float deltaTime) override;
	//�I��
	virtual void Finalize() override;
	//�I���`�F�b�N
	virtual bool IsEnd() override;
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() const override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
};

#endif // !ENEMY_COMMAND_SHOT
