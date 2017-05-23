#ifndef ENEMYCOMMANDSTNDBY_H_
#define ENEMYCOMMANDSTNDBY_H_

#include "../../Base/EnemyCommandBase.h"

//3�񋲂܂ꂽ��w������ɓ���
class EnemyCommandStandby : public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandStandby(const EnemyBasePtr& enemy, const FourDirection front, const MapType type);
	//�X�V
	virtual void Update(float deltaTime) override;
	//�I��
	virtual void Finalize() override;
};

#endif // !ENEMYCOMMANDSTNDBY_H_

