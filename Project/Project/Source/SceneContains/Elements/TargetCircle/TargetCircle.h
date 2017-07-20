#ifndef TARGETCIRCLE_H_
#define TARGETCIRCLE_H_
#include "../../../ActorContains/Actor/Actor.h"
#include "../../../CharacterContains/EnemyContains/Entity/Enemys/Base/EnemyBasePtr.h"
class TargetCircle : public Actor
{
public:
	TargetCircle(IWorld * world, const IGameManagerPtr & gameManager,const EnemyBasePtr& targetEnemy);

protected:
	//������
	void onInitialize() override;
	//�X�V
	void OnLateUpdate() override;

private:
	//�ڕW�G�̈ʒu�ɍ��킹��
	void MatchPos();

protected:
	EnemyBasePtr p_TargetEnemy;
};
#endif // !TARGETCIRCLE_H_
