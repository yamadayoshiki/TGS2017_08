#ifndef ENEMYCOMMANDGENERATE_H_
#define ENEMYCOMMANDGENERATE_H_

#include "../../Base/EnemyCommandBase.h"

//���̃G�l�~�[�����}��
class EnemyCommandGenerate : public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandGenerate(
		const EnemyBasePtr& enemy,
		const MapType type,
		const TurnDirection turnDirection);
	//�f�X�g���N�^
	~EnemyCommandGenerate();
	//�I��
	virtual void Finalize() override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) override;
};

#endif // !ENEMYCOMMANDGENERATE_H_
