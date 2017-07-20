#ifndef GAMEPLAYREADY_H_
#define GAMEPLAYREADY_H_
#include "../../Scene/ChildScene.h"
#include <vector>
class AnimationSpriteBase;
//ゲームプレイ準備
class GamePlayReady : public ChildScene {
public:
	GamePlayReady();

protected:
	// 開始     
	virtual void OnStart() override;
	// 更新     
	virtual void OnUpdate(float deltaTime) override;
	// 描画     
	virtual void OnDraw()const override;
	//終了
	virtual void OnEnd()override;

protected:
	//変更
	void ChangeSprite();

private:
	std::vector<std::shared_ptr<AnimationSpriteBase>> m_SpriteVector;
	int m_CurIndex;
};
#endif // !GAMEPLAYREADY_H_