#ifndef ENEMYMANAGER_H_
#define ENEMYMANAGER_H_
#include "../../../ActorContains/Actor/Actor.h"
#include "../Entity/Enemys/Base/EnemyBasePtr.h"
#include <vector>
#include <unordered_map> 

class EnemyManager : public Actor
{
	struct TagetEnemy {
		ActorName m_Name;
		std::weak_ptr<ITexture> p_Texture;
		TagetEnemy(const ActorName name, const ITexturePtr& texture) :m_Name(name), p_Texture(texture) {}
	};

	enum class EnemyGroup {
		Normal,		//通常敵
		Enemy09,	//Enemy09のみ
		Offensive,	//他エネミーにも攻撃する
		Invincible,	//他と干渉しない無敵
		BreakWall,	//壊れるブロック
	};
public:
	//デフォルトコンストラクタ
	EnemyManager();

public:
	//子の追加
	void addChild(const ActorPtr& child) override;
	//子を削除する(死んだ子の削除)
	void removeChildren_dead() override;

public:
	//セットアップ
	void SetUp(
		IWorld* world,
		const IGameManagerPtr& gameManager);
	//衝突
	void EnemyCollide();
	//討伐可能敵の数の取得
	int GetSurviverSum() const;
	//討伐可能敵のテクスチャ配列の取得
	void GetTagetEnemyTextures(std::vector<ITexturePtr>& out);
	//討伐可能敵のテクスチャ配列の数の取得
	int GetNumTagetEnemyTextures();

private:
	//倒せる敵か否か(スマポ参照)
	bool CanDead(const EnemyBasePtr& enemy);
	//倒せる敵か否か(実体参照)
	bool CanDead(const EnemyBase& enemy);

private:
	int m_SurviverSum;	//生き残っている討伐可能敵の数
	std::vector<TagetEnemy> m_TagetEnemyTextures;	//討伐目標敵のテクスチャの配列
	std::unordered_map<EnemyGroup, ActorPtr> m_Enemys;	//エネミーグループ
};
#endif