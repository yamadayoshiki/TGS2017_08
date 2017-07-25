#ifndef ENEMYMANAGER_H_
#define ENEMYMANAGER_H_
#include "../../../ActorContains/Actor/Actor.h"
#include "../Entity/Enemys/Base/EnemyBasePtr.h"
#include <vector>
#include <unordered_map> 
class EnemyGroup;
class EnemyManager : public Actor,public std::enable_shared_from_this<EnemyManager>
{
	struct TagetEnemy {
		ActorName m_Name;
		std::weak_ptr<ITexture> p_Texture;
		TagetEnemy(const ActorName name, const ITexturePtr& texture) :m_Name(name), p_Texture(texture) {}
	};

	enum class EnemyGroupName {
		Normal,		//�ʏ�G
		Enemy09,	//Enemy09�̂�
		Offensive,	//���G�l�~�[�ɂ��U������
		Invincible,	//���Ɗ����Ȃ����G
		BreakWall,	//����u���b�N
	};
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyManager();

public:
	//�q�̒ǉ�
	void addChild(const ActorPtr& child) override;

public:
	//�Z�b�g�A�b�v
	void SetUp(
		IWorld* world,
		const IGameManagerPtr& gameManager);
	//�Փ�
	void EnemyCollide();
	//�����\�G�̐��̎擾
	int GetSurviverSum() const;
	//�����\�G�̃e�N�X�`���z��̎擾
	void GetTagetEnemyTextures(std::vector<ITexturePtr>& out);
	//�����\�G�̃e�N�X�`���z��̐��̎擾
	int GetNumTagetEnemyTextures();
	//�����\�G�̐��̌��Z
	void DecreaseSurviverSum(int num);

private:
	//�|����G���ۂ�(�X�}�|�Q��)
	bool CanDead(const EnemyBasePtr& enemy);
	//�|����G���ۂ�(���̎Q��)
	bool CanDead(const EnemyBase& enemy);

private:
	int m_SurviverSum;	//�����c���Ă��铢���\�G�̐�
	std::vector<TagetEnemy> m_TagetEnemyTextures;	//�����ڕW�G�̃e�N�X�`���̔z��
	std::unordered_map<EnemyGroupName, std::shared_ptr<EnemyGroup>> m_Enemys;	//�G�l�~�[�O���[�v
};
#endif