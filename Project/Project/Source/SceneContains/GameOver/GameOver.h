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
	virtual void OnStart() override;
	// 更新     
	virtual void OnUpdate(float deltaTime) override;
	// 描画     
	virtual void OnDraw()const override;
	//終了
	virtual void OnEnd() override;
};

#endif // !GAMEOVER_H_
