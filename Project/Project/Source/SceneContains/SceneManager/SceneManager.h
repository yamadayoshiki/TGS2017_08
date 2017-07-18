#ifndef SCENEMANAGER_H_ 
#define SCENEMANAGER_H_ 

#include "../IScenePtr.h"
#include <unordered_map> 

enum class SceneName;
enum class EventMessage;
// シーン管理クラス
class SceneManager
{
public:
	// コンストラクタ     
	SceneManager();
	// セットアップ
	void SetUp();
	// 初期化     
	void Initialize();
	// 更新     
	void Update(float deltaTime);
	// 描画     
	void Draw() const;
	// 終了     
	void End();
	// シーンの追加    
	virtual void Add(SceneName name, const IScenePtr& scene);
	// シーンの変更     
	void Change(SceneName name);
	// シーン名の取得     
	SceneName GetSceneName();
	// メッセージ処理
	void HandleMessage(EventMessage message, void* param);
	// コピー禁止     
	SceneManager(const SceneManager& other) = delete;
	SceneManager& operator = (const SceneManager& other) = delete;

protected:
	// シーン     
	std::unordered_map<SceneName, IScenePtr> m_SceneDic;
	// 現在のシーン     
	IScenePtr m_CurrentScene;
};

#endif