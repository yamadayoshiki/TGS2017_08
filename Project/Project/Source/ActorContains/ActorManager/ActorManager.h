#ifndef ACTOR_MANAGER_H_ 
#define ACTOR_MANAGER_H_ 

#include "../Actor/Actor.h" 
#include <unordered_map> 

enum class ActorGroup;

// アクターマネージャー 
class ActorManager {
public:
	// コンストラクタ     
	ActorManager();
	// 初期化     
	void initialize();
	// 更新     
	void update(float deltaTime);
	// 描画     
	void draw() const;
	// アクターの追加     
	void addActor(ActorGroup group, const ActorPtr& actor);
	// アクターの検索     
	ActorPtr findActor(const ActorName& name);
	// メッセージ処理     
	void handleMessage(EventMessage message, void* param);
	// コピー禁止     
	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator = (const ActorManager& other) = delete;
	//任意の衝突判定
	void OptionalCollide(Actor* actor, ActorGroup actorGroup);

private:
	// 衝突判定     
	void collide();

private:
	// ルートノード     
	Actor m_root;
	// アクターグループ     
	std::unordered_map<ActorGroup, ActorPtr> m_actors;
};

#endif