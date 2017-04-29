#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "../IGameManager.h"

class GameManager :public IGameManager
{
public:
	//コンストラクタ
	GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState);
	//更新処理
	void Update();
	//コピー禁止
	GameManager& operator = (const GameManager& other) = delete;
	GameManager(const GameManager& other) = delete;

public:
	//コンテンツの読み込み
	void LoadContent();
	//コンテンツの削除
	void UnLoadContent();
	//レンダラーの取得
	virtual Renderer2DPtr GetRenderer2D() override;
	//インプットステイトの取得
	virtual InputStatePtr GetInputState() override;
	// シーンの終了の取得
	virtual bool IsEndScene() override;
	// シーンの終了
	virtual void EndScene(bool end = false) override;

protected:
	//終了処理
	void Finalize() override;
private:
	Renderer2DPtr p_Renderer2D;	//レンダラー
	InputStatePtr p_InputState;	//インプットステイト
	bool m_IsEnd;				//シーンの終了
};

#endif // !GAMEMANAGER_H_