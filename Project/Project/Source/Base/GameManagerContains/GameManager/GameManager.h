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
	//シーンのEnumの取得
	virtual EnumRapPtr<SceneName> GetSceneEnum() override;
	//プレイヤーパラメーターの取得
	virtual Player_Parameter GetPlayerParameter() override;
	//プレイヤーパラメーターの設定				
	virtual void SetPlayerParameter(const Player_Parameter& parameter) override;

protected:
	//終了処理
	void Finalize() override;
private:
	Renderer2DPtr p_Renderer2D;		//レンダラー
	InputStatePtr p_InputState;		//インプットステイト
	EnumRapPtr<SceneName> p_SceneEnum;	//シーンEnum
	Player_Parameter	m_Parameter;	//プレイヤーパラメーター
};

#endif // !GAMEMANAGER_H_