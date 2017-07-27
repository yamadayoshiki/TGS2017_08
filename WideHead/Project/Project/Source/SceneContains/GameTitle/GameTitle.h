#ifndef GAMETITLE_H_
#define GAMETITLE_H_

#include "../Scene/Scene.h"
class AnimationFont;
class DropSprite;
class Button;
class SceneChildMgr;
//タイトルシーン
class GameTitle : public Scene
{
public:
	// コンストラクタ    
	GameTitle(const IGameManagerPtr& gameManager);

protected:
	// セットアップ
	virtual void SetUp() override;
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
	//終了
	virtual void OnEnd()override;

public:
	//タイトルロゴの取得
	std::weak_ptr<DropSprite> GetTitle();
	//Bボタンを押せの取得
	std::weak_ptr<AnimationFont> GetPushBMessage(const int index);
	//ポーズ画面ボタンUIの取得
	std::weak_ptr<Button> GetButtonUI();

public:
	std::weak_ptr<DropSprite> p_Title;						//タイトルロゴ
	std::weak_ptr<AnimationFont> p_PushBMessage[13];		//Bボタンを押せ
	std::weak_ptr<Button> p_Button;							//ボタンUI

	std::unique_ptr<SceneChildMgr>				//子シーン管理
		p_SceneChildMgr;
};

#endif