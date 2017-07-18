#ifndef GUIDE_H_
#define GUIDE_H_
#include "../../../ActorContains/Actor/Actor.h"

class AnimationTexture;
class Texture;

class Guide : public Actor
{
	enum class State {
		Tutorial1 = 0,
		Tutorial2,
		Tutorial3,
		Tutorial4,
		Tutorial5,
		Tutorial6,
		Tutorial7,
		Tutorial8,
	};

public:
	Guide(
		IWorld* world,
		const IGameManagerPtr& gameManager);
	~Guide();

protected:
	//更新
	void onUpdate(float deltaTime) override;
	//メッセージ処理
	virtual void onMessage(EventMessage message, void* param)override;

public:
	void Change(const State next);

private:
	std::unique_ptr<Texture> p_RightBG;				//右の背景
	std::unique_ptr<AnimationTexture> p_Button;		//ボタン
	std::unique_ptr<AnimationTexture> p_Motion;		//プレイヤーの動き
	std::unique_ptr<Texture> p_LeftItem;			//左の項目

	int m_Timer;

	State m_CurState;
};

#endif // !GUIDE_H_
