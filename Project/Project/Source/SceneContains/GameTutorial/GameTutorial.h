#ifndef GAMETUTORIAL_H_
#define GAMETUTORIAL_H_
#include "../Scene/Scene.h"
class Button;
class Sprite;
class SceneChildMgr;
class Guide;
class BreakWall;
class Enemy05;
class Enemy12;
class GameTutorial : public Scene
{
public:
	GameTutorial(const IGameManagerPtr& gameManager);

protected:
	// セットアップ
	virtual void SetUp() override;
	// 開始
	virtual void OnStart() override;
	// 更新
	virtual void OnUpdate(float deltaTime) override;
	//終了
	virtual void OnEnd()override;
	// メッセージ処理
	virtual void HandleMessage(EventMessage message, void* param)override;
public:
	//ポーズ画面ボタンUIの取得
	std::weak_ptr<Button> GetButtonUI();
	//ポーズ画面背景の取得
	std::weak_ptr<Sprite> GetPauseBack();
	//ガイドの取得
	std::shared_ptr<Guide> GetGuide();
	//右BreakWallの取得
	std::shared_ptr<BreakWall> GetBreakWall();
	//Enemy05の取得
	std::shared_ptr<Enemy05> GetEnemy05();
	//Enemy12の取得
	std::shared_ptr<Enemy12> GetEnemy12();
protected:
	//Mapデータの設定
	virtual void MapSetDeta();
protected:
	std::unique_ptr<SceneChildMgr>				//子シーン管理
		p_SceneChildMgr;

private:
	std::weak_ptr<Button> p_ButtonUI;			//ポーズ画面ボタンUI
	std::weak_ptr<Sprite> p_PauseBack;			//ポーズ画面背景
	std::shared_ptr<Guide> p_Guide;
	std::shared_ptr<BreakWall> p_BreakWall;
	std::shared_ptr<Enemy05> p_Enemy05;
	std::shared_ptr<Enemy12> p_Enemy12;
};

#endif // !GAAMETUTORIAL_H_
