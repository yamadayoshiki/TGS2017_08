#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
class World;
class Number;
class Button;
class Sprite;
class SceneChildMgr;
//ゲーム中
class GamePlay : public Scene
{
public:
	// コンストラクタ    
	explicit GamePlay(const IGameManagerPtr& gameManager);

protected:
	// セットアップ
	virtual void SetUp() override;
	// 開始
	virtual void OnStart() override;
	// 更新
	virtual void OnUpdate(float deltaTime) override;
	// 描画     
	virtual void OnDraw()const override;
	//終了
	virtual void OnEnd()override;
	// メッセージ処理
	virtual void HandleMessage(EventMessage message, void* param)override;

public:
	//スコアの取得
	std::weak_ptr<Number> GetScoreUI();
	//プレイヤー残機の取得
	std::weak_ptr<Number> GetPlayerRemainingUI();
	//ポーズ画面ボタンUIの取得
	std::weak_ptr<Button> GetButtonUI();
	//ポーズ画面背景の取得
	std::weak_ptr<Sprite> GetPauseBack();

protected:
	//Mapデータの設定
	virtual void MapSetDeta();

protected:
	std::weak_ptr<Number> p_ScoreUI;			//スコア
	std::weak_ptr<Number> p_PlayerRemainingUI;	//プレイヤー残機
	std::weak_ptr<Button> p_ButtonUI;			//ポーズ画面ボタンUI
	std::weak_ptr<Sprite> p_PauseBack;			//ポーズ画面背景

	std::unique_ptr<SceneChildMgr>				//子シーン管理
		p_SceneChildMgr;
};

#endif