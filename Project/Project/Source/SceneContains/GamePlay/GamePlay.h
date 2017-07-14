#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
class World;

//ゲーム中
class GamePlay : public Scene
{
public:
	// コンストラクタ    
	GamePlay(const IGameManagerPtr& gameManager);

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
	// 描画     
	virtual void OnDraw()const;
	//終了
	virtual void OnEnd()override;

private:
	//Mapデータの設定
	void MapSetDeta();
	//ポーズの更新
	void PauseUpdate();

private:
	Texture2DParameterSPtr p_Back;
	int m_Back;
};

#endif