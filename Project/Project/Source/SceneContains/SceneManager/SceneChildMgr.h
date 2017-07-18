#ifndef SCENECHILDMGR_H_
#define SCENECHILDMGR_H_
#include "SceneManager.h"
//シーンの入れ子
class SceneChildMgr : public SceneManager
{
public:
	explicit SceneChildMgr(const IScenePtr& parent);
	~SceneChildMgr();

public:
	// シーンの追加    
	void Add(SceneName name, const IScenePtr& child) override;

public:
	//子の設定
	void SetUpChild();
	//子のworld解放
	void ReleaseWorld();

private:
	// コピー禁止     
	SceneChildMgr(const SceneChildMgr& other) = delete;
	SceneChildMgr& operator = (const SceneChildMgr& other) = delete;

private:
	ISceneWPtr p_Parent;	//親
};
#endif // !SCENECHILDMGR_H_