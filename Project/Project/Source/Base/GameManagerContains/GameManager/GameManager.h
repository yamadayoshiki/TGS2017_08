#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "../IGameManager.h"

class GameManager:public IGameManager
{
public:
	//コンストラクタ
	GameManager(Renderer2D* renderer2D);
	//コンテンツの読み込み
	void LoadContent() override;
	//コンテンツの削除
	void UnLoadContent() override;
	//コピー禁止
	GameManager& operator = (const GameManager& other) = delete;
	GameManager(const GameManager& other) = delete;

public:
	//レンダラーの取得
	Renderer2D* GetRenderer2D() override;

protected:
	//終了処理
	void Finalize() override;

private:
	Renderer2D* p_Renderer2D;//レンダラー
};

#endif // !GAMEMANAGER_H_