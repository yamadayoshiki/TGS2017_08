#ifndef IWORLD_H_ 
#define IWORLD_H_ 

#include <gslib.h>

#include "../ActorContains/ActorPtr.h"
#include "../ActorContains/ActorName.h"
#include "../Map/MapPtr.h"

enum class ActorGroup;
enum class EventMessage;
enum class SceneName;
class CharacterFactory;
namespace Body { class BodyFactory; }

// ワールド抽象インターフェース 
class IWorld
{
public:
	// 仮想デストラクタ
	virtual ~IWorld() {	}
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
	// メッセージの送信(指定アクターのみ)
	virtual void sendMessageOne(EventMessage message, Actor& actor, void* param = nullptr) = 0;
	// シーンの終了
	virtual void EndRequest(const SceneName& name) = 0;
	//マップの取得
	virtual MapPtr GetMap() = 0;
	//キャラクターファクトリーの取得
	virtual CharacterFactory* GetCharacterFactory() const = 0;
	//衝突判定図形ファクトリーの取得
	virtual Body::BodyFactory* GetBodyFactory() const = 0;
};

#endif