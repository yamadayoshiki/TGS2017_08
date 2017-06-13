#ifndef ENEMYCOMMANDENEMY09STANDBY_H_
#define ENEMYCOMMANDENEMY09STANDBY_H_

#include "../../Base/EnemyCommandBase.h"
#include <map>

class FrontChipList;

class EnemyCommandEnemy09Standby : public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandEnemy09Standby(
		const EnemyBasePtr& enemy);
	//�f�X�g���N�^
	~EnemyCommandEnemy09Standby();

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) override;

protected:
	//�v���C���[��X����������Y���ŏd�Ȃ��Ă��邩
	bool IsAxisOverlap();

private:
	//�w������̕ǃ}�X�܂ł̋����̐ݒ�
	void SetSpeaceNum(const FourDirectionName name);

protected:
	FrontChipList* p_FrontChipList;							//�O���}�X�Ǘ�
	std::unordered_map<FourDirection, int> m_SpeaceNumMap;	//�������Ƃ̕ǃ}�X�܂ł̐�
};

#endif // !ENEMYCOMMANDENEMY09STANDBY_H_