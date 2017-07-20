#ifndef WORLD_H_
#define WORLD_H_ 

#include "../IWorld.h" 
#include "../../ActorContains/ActorManager/ActorManager.h"
#include "../../ActorContains/ActorGroup.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../../ActorContains/ActorPtr.h"
#include"../../Map/Map.h"

#include"../../ActorContains/ActorManager/ActorManagerPtr.h"
#include"../../MapGenerator/MapGeneratorPtr.h"
#include "../../CharacterContains/Factory/CharacterFactoryPtr.h"
#include "../../ActorContains/BodyContains/Factory/BodyFactoryPtr.h"

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
	// セットアップ
	void SetUp(const IGameManagerPtr& gameManager);
	// 更新    
	void update(float deltaTime);
	// 描画     
	void draw() const;
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
	// メッセージの送信(指定アクター+子)
	virtual void sendMessage(EventMessage message, Actor& actor, void* param = nullptr) override;
	// メッセージの送信(指定アクターのみ)
	virtual void sendMessageOne(EventMessage message, Actor& actor, void* param = nullptr) override;

	//生成
	void generate(const IWorldPtr world, const IGameManagerPtr& gameManager, const std::string& file_name);
	//マップの取得
	MapPtr GetMap() override;
	//キャラクター工場の設定
	void SetCharacterFactory(CharacterFactory* characterFactory);
	//キャラクター工場の取得
	CharacterFactory* GetCharacterFactory() const override;
	//衝突判定図形ファクトリーの取得
	Body::BodyFactory* GetBodyFactory() const override;
	//マップジェネレーターの生成
	void SetMapGenerator(const IWorldPtr& world, const IGameManagerPtr& gameManager);

	// シーンの終了の取得
	virtual bool IsEnd();
	// シーンの終了
	virtual void EndRequest(const SceneName& name) override;
	// シーンの終了
	virtual void ResetEnd();
	// シーンの終了
	virtual SceneName NextScene();
	// 討伐目標敵の数の取得
	int GetSurviverSum();

	// コピー禁止  
	World(const World& other) = delete;
	World& operator = (const World& other) = delete;

private:
	ActorManagerPtr p_Actors;					//アクター管理
	MapGeneratorPtr p_MapGenerator;				//マップ生成クラス
	SceneName m_NextScene;						//次のシーン
	bool m_IsEnd;								//終了しているか
	CharacterFactoryUPtr p_CharacterFactory;	//キャラクター工場
	Body::BodyFactoryUPtr p_BodyFactory;		//衝突判定図形ファクトリー
};
#endif