#ifndef IGAMEMANAGER_H_
#define IGAMEMANAGER_H_

#include "../../Utility/Rederer2D/Renderer2DPtr.h"
#include "../../Utility/InputState/InputStatePtr.h"
#include"../../Utility/Score/ScorePtr.h"
#include "../../Utility/EnumRap/EnumRapPtr.h"
#include "../../SceneContains/SceneName.h"
#include "../../CharacterContains/PlayerContains/Player/Player_Parameter.h"
#include "../../DrawManager/DrawManagerPtr.h"
#include <iostream>
class SceneManager;
//ゲームマネージャーインターフェイス
class IGameManager
{
public:
	//仮想デストラクタ
	virtual ~IGameManager() {}

public:
	//指定コンテンツ読み込み
	virtual void LoadTexture(const std::string registerName, const std::string fileName) = 0;
	//指定コンテンツ破棄
	virtual void UnLoadTexture(const std::string registerName) = 0;
	//描画管理の取得
	virtual DrawManagerSPtr GetDrawManager() = 0;
	//インプットステイトの取得
	virtual InputStatePtr GetInputState() = 0;
	//シーンのEnumの取得
	virtual EnumRapPtr<SceneName> GetSceneEnum() = 0;
	//プレイヤーパラメーターの取得
	virtual Player_Parameter& GetPlayerParameter() = 0;
	//プレイヤーパラメーターの設定
	virtual void SetPlayerParameter(const Player_Parameter& parameter) = 0;
	//スコアの取得
	virtual ScorePtr GetScore() = 0;
	//シーンマネージャーの取得
	virtual std::shared_ptr<SceneManager> GetSceneManager() = 0;

	//マップの設定と取得
	virtual void set_MapOrder(int MapOrder) = 0;
	virtual int get_MapOrder() = 0;


protected:
	//終了処理
	virtual void Finalize() {};

};
#endif // !IGAMEMANAGER_H_
