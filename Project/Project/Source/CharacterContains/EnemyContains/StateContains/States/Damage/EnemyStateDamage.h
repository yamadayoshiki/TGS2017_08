#ifndef ENEMYSTATEDAMAGE_H_
#define ENEMYSTATEDAMAGE_H_
#include "../Base/EnemyStateBase.h"
#include "../../../../../ActorContains/ActorPtr.h"
class EnemyStateDamage : public EnemyStateBase
{
public:
	EnemyStateDamage(const EnemyBasePtr& enemy,const int damage = 5);
protected:
	// �e��ŗL�̏�����
	virtual void unique_init() override;
	// �e��ŗL�̍X�V����
	virtual void update(float deltaTime) override;
	// �e��ŗL�̏I������
	virtual void end() override;

private:
	ActorPtr p_Explosion;
	int m_Damage;
};

#endif // !1
