#ifndef WORLD_H_
#define WORLD_H_ 

#include "../IWorld.h" 
#include "../../ActorContains/ActorManager/ActorManager.h"
#include "../../ActorContains/ActorPtr.h"

enum class EventMessage;

// ワールドクラス
class World :public IWorld
{
public:
	// コンストラクタ  
	World();
	// 更新    
	void update(float deltaTime);
	// 描画     
	void draw() const;
	// 描画
	void Draw() const;
	//終了処理
	void Finalize() override;
	// メッセージ処理  
	void handleMessage(EventMessage message, void* param);
	// アクターの追加   
	virtual void addActor(ActorGroup group, const ActorPtr& actor) override;
	// アクターの検索    
	virtual ActorPtr findActor(const ActorName& name) override;
	// アクターと任意の衝突判定
	virtual void OptinalCollide(Actor* actor, ActorGroup actorGroup) override;
	// メッセージの送信    
	virtual void sendMessage(EventMessage message, void* param = nullptr) override;
	// コピー禁止  
	World(const World& other) = delete;
	World& operator = (const World& other) = delete;

private:
	// アクターマネージャー
	ActorManager* p_Actors;
};
#endif