#ifndef GAMERESULT_H_
#define GAMERESULT_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"

class World;
class Number;
class Button;
class Sprite;
class Rank;
class SceneChildMgr;

//ゲームリザルト
class GameResult : public Scene
{
public:
	// コンストラクタ    
	GameResult(const IGameManagerPtr& gameManager);

protected:
	// セットアップ
	void SetUp() override;
	// 開始     
	virtual void OnStart() override;
	// 更新     
	virtual void OnUpdate(float deltaTime) override;
	//描画
	virtual void OnDraw()const override;
	//終了
	virtual void OnEnd() override;
	// メッセージ処理
	virtual void HandleMessage(EventMessage message, void* param)override;

public:
	//スコアの取得
	std::weak_ptr<Number> GetScoreUI();
	//ランクの取得
	std::weak_ptr<Rank> GetRankUI();
	//リザルト結果の基盤画像の取得
	std::weak_ptr<Sprite> GetPlatform();
	//ブロック画像の取得
	std::weak_ptr<Sprite> GetBlock();
	//ブロック2画像の取得
	std::weak_ptr<Sprite> GetBlock2();

private:
	std::weak_ptr<Number> p_ScoreUI;
	std::weak_ptr<Rank> p_RankUI;
	std::weak_ptr<Sprite> p_Platform;
	std::weak_ptr<Sprite> p_Block;
	std::weak_ptr<Sprite> p_Block2;

	std::unique_ptr<SceneChildMgr>
		p_SceneChildMgr;
};

#endif