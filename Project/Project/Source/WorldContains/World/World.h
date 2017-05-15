#ifndef WORLD_H_
#define WORLD_H_ 

#include "../IWorld.h" 
#include "../../ActorContains/ActorManager/ActorManager.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../../ActorContains/ActorPtr.h"
#include"../../Map/Map.h"

#include"../../ActorContains/ActorManager/ActorManagerPtr.h"
#include"../../MapGenerator/MapGeneratorPtr.h"

#include"../../CharacterContains/CharacterManagerContains/CharacterManager/CharacterManager.h"

enum class EventMessage;
enum class SceneName;

// ワールドクラス
class World :public IWorld
{
public:
	// コンストラクタ  
	World();
	// デストラクタ
	World::~World();
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

	//キャラクターマネージャーの取得
	virtual CharacterManager* getCharacterManager()override;
	//キャラクターマネージャーの設定
	virtual void setCharacterManager(CharacterManager* characterManager)override;

	//生成
	void generate(const IWorldPtr world, const IGameManagerPtr& gameManager, const std::string& file_name);
	//マップの取得
	Map& GetMap();

	// シーンの終了の取得
	virtual bool IsEnd();
	// シーンの終了
	virtual void EndRequest(const SceneName& name);
	// シーンの終了
	virtual void ResetEnd();
	// シーンの終了
	virtual SceneName NextScene();

	// コピー禁止  
	World(const World& other) = delete;
	World& operator = (const World& other) = delete;

private:
	// アクターマネージャー
	ActorManagerPtr p_Actors;
	//マップジェネレータ
	MapGeneratorPtr p_MapGenerator;
	// 
	SceneName m_NextScene;
	//キャラクターマネージャー
	CharacterManager* p_CharacterManager;
	// 
	bool m_IsEnd;	
};
#endif