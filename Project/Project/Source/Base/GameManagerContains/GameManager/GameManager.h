#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "../IGameManager.h"

class GameManager :public IGameManager
{
public:
	//コンストラクタ
	GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState, const ScorePtr& score);
	//仮想デストラクタ
	virtual ~GameManager() { Finalize(); }
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//コピー禁止
	GameManager& operator = (const GameManager& other) = delete;
	GameManager(const GameManager& other) = delete;

public:
	//コンテンツの読み込み
	void LoadContent();
	//コンテンツの削除
	void UnLoadContent();
	//指定コンテンツ読み込み
	void LoadTexture(const std::string registerName, const std::string fileName) override;
	//指定コンテンツ破棄
	void UnLoadTexture(const std::string registerName)override;
	//レンダラーの取得
	//Renderer2DPtr GetRenderer2D() override;
	//描画管理の取得
	DrawManagerSPtr GetDrawManager() override;
	//インプットステイトの取得
	virtual InputStatePtr GetInputState() override;
	//シーンのEnumの取得
	virtual EnumRapPtr<SceneName> GetSceneEnum() override;
	//プレイヤーパラメーターの取得
	virtual Player_Parameter& GetPlayerParameter() override;
	//プレイヤーパラメーターの設定				
	virtual void SetPlayerParameter(const Player_Parameter& parameter) override;
	//スコアの取得
	virtual ScorePtr GetScore()override;
	//シーンマネージャーの設定
	void SetSceneManager(const std::shared_ptr<SceneManager>& sceneMgr);
	//シーンマネージャーの取得
	std::shared_ptr<SceneManager> GetSceneManager()override;

	void set_MapOrder(int MapOrder)override;
	int get_MapOrder()const override;

protected:
	//終了処理
	void Finalize() override;
private:
	Renderer2DPtr p_Renderer2D;			//レンダラー
	DrawManagerSPtr p_DrawManager;		//描画管理
	InputStatePtr p_InputState;			//インプットステイト
	ScorePtr	  p_Score;				//スコア
	EnumRapPtr<SceneName> p_SceneEnum;	//シーンEnum
	Player_Parameter	m_Parameter;	//プレイヤーパラメーター
	int MapOrder_;

	std::weak_ptr<SceneManager> p_SceneMgr;
};

#endif // !GAMEMANAGER_H_