#ifndef ESENTRY_H_
#define ESENTRY_H_
#include "../Base/EnemyStateBase.h"
class AnimationTexture;
class ESEntry : public EnemyStateBase
{
public:
	//�R���X�g���N�^
	ESEntry(const EnemyBasePtr& enemy);

public:
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
	//�I��
	virtual void end() override;
	
private:
	std::shared_ptr<AnimationTexture> p_EntrySmork;
	int m_Timer;
};
#endif // !ESENTRY_H_
