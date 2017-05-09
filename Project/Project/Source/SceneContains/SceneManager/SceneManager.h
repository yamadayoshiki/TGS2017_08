#ifndef SCENEMANAGER_H_ 
#define SCENEMANAGER_H_ 

#include "../IScenePtr.h"
#include <unordered_map> 

enum class SceneName;

// シーン管理クラス
class SceneManager
{
public:
	// コンストラクタ     
	SceneManager();
	// 初期化     
	void Initialize();
	// 更新     
	void Update(float deltaTime);
	// 描画     
	void Draw() const;
	// 終了     
	void End();
	// シーンの追加    
	void Add(SceneName name, const IScenePtr& scene);
	// シーンの変更     
	void Change(SceneName name);
	// シーン名の取得     
	SceneName GetSceneName();
	// コピー禁止     
	SceneManager(const SceneManager& other) = delete;
	SceneManager& operator = (const SceneManager& other) = delete;

private:
	// シーン     
	std::unordered_map<SceneName, IScenePtr> m_SceneDic;
	// 現在のシーン     
	IScenePtr m_CurrentScene;
};

#endif