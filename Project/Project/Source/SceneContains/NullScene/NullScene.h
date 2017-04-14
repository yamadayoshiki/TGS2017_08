#ifndef NULLSCENE_H_ 
#define NULLSCENE_H_ 

#include "../Scene/Scene.h" 

// 空のシーン 
class NullScene : public Scene
{
public:
	// コンストラクタ    
	NullScene();
	// 描画     
	virtual void Draw() const override;
	// 次のシーンを返す     
	virtual SceneName Next() const override;
	// 終了     
	virtual void End() override;

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
};

#endif