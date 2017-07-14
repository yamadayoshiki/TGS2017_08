#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include "../../DrawManager/DrawOrderObject.h"
class World;

class GameOver : public Scene
{
public:
	//コンストラクタ
	GameOver(const IGameManagerPtr& gameManager);

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
	// 描画     
	virtual void OnDraw()const;
	//終了
	virtual void End();

private:
	//選択の更新
	void SelectUpdate();
	//テクスチャのパラメータ
	Texture2DParameterSPtr p_OverParam;
	Texture2DParameterSPtr p_ResultParam;
	Texture2DParameterSPtr p_PauseRTParam;
	Texture2DParameterSPtr p_CursorParam;
	//テクスチャの管理番号
	DrawOrderID m_OrverNum;
	DrawOrderID m_ResultNum;
	DrawOrderID m_PauseRTNum;
	DrawOrderID m_CursorNum;
};

#endif // !GAMEOVER_H_
