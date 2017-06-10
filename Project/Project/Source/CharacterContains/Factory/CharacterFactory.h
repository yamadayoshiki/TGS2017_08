#ifndef CHARACTERFACTORY_H_
#define CHARACTERFACTORY_H_

#include <map>
#include "../../ActorContains/ActorPtr.h"
#include "../../WorldContains/IWorldPtr.h"
#include "../../Base/GameManagerContains/IGameManagerPtr.h"

enum class ActorName;

//キャラクター工場
class CharacterFactory
{
private:
	struct ActorData {
		ActorWPtr parent;	// 生成するアクターの親
		ActorUPtr child;	// 生成するアクター自身
	};

public:
	//コンストラクタ
	CharacterFactory(
		const IWorldPtr& world, 
		const IGameManagerPtr& gameManager);
	//デストラクタ
	~CharacterFactory();

	//生成
	void Generate(int x, int y, int csvData);

private:
	std::map<ActorName, ActorWPtr> m_ParentMap;	//親
	std::map<int, ActorData> m_GenerateMap;		//生成キャラ用マップ

	IWorldWPtr p_IWorld;						//ワールド
	IGameManagerWPtr p_IGameManager;			//ゲームマネージャー
};

#endif