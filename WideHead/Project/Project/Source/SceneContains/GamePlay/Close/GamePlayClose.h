#ifndef GAMEPLAYCLOSE_H_
#define GAMEPLAYCLOSE_H_
#include "../../Scene/ChildScene.h"
#include <map>
class Respawn;
class Texture;
class ZoomSprite;
class GamePlayClose : public ChildScene
{
	enum class State {
		Stop = 0,
		Clear,
		End,
	};
public:
	GamePlayClose();

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
	void ChangeState(const State next);

private:
	std::map<State, std::shared_ptr<ZoomSprite>> m_SpriteMap;
	State m_CurState;
	std::unique_ptr<Respawn> p_Respown;
	std::unique_ptr<Texture> p_BlackScreen;
};
#endif // !GAMEPLAYCLOSE_H_
