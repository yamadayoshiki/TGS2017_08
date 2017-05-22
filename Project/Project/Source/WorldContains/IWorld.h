#ifndef IWORLD_H_ 
#define IWORLD_H_ 

#include <gslib.h>

#include "../ActorContains/ActorPtr.h"
#include "../ActorContains/ActorName.h"

enum class ActorGroup;
enum class EventMessage;
enum class SceneName;
class Map;

// ワールド抽象インターフェース 
class IWorld
{
public:
	// 仮想デストラクタ
	virtual ~IWorld() {
		Finalize();
	}
	// アクターの追加   
	virtual void addActor(ActorGroup group, const ActorPtr& actor) = 0;
	// アクターの検索     
	virtual ActorPtr findActor(const ActorName& name) = 0;
	//任意のアクターグループと衝突判定
	virtual void OptinalCollide(Actor* actor, ActorGroup actorGroup) = 0;
	// メッセージの送信    
	virtual void sendMessage(EventMessage message, void* param = nullptr) = 0;
	// メッセージの送信(指定アクター)
	virtual void sendMessage(EventMessage message, Actor& actor, void* param = nullptr) = 0;
	// シーンの終了
	virtual void EndRequest(const SceneName& name) = 0;
	//マップの取得
	virtual Map& GetMap() = 0;
protected:
	// 終了処理
	virtual void Finalize() {}
};

#endif