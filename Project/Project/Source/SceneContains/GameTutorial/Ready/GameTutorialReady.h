#ifndef GAMETUTORIALREADY_H_
#define GAMETUTORIALREADY_H_
#include "../../Scene/ChildScene.h"
#include <map>
class ZoomSprite;
//ゲームプレイ準備
class GameTutorialReady : public ChildScene{
	enum class State {
		Title = 0,
		Start,
		End,
	};
public:
	GameTutorialReady();

protected:
	// 開始     
	virtual void OnStart() override;
	// 更新     
	virtual void OnUpdate(float deltaTime) override;
	//終了
	virtual void OnEnd()override;

protected:
	//変更
	void ChangeState(const State next);

private:
	std::map<State, std::shared_ptr<ZoomSprite>>
		m_SpriteMap;
	State m_CurState;
};
#endif // !GAMEPLAYREADY_H_