#ifndef GAMETUTORIAL_H_
#define GAMETUTORIAL_H_

#include "../Scene/Scene.h"

class GameTutorial : public Scene
{
public:
	GameTutorial(const IGameManagerPtr& gameManager);

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
	// 描画     
	virtual void OnDraw()const;
	//終了
	virtual void End()override;
};

#endif // !GAAMETUTORIAL_H_
