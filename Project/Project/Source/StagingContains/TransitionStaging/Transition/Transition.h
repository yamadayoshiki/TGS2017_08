#pragma once

#include "../../../Base/GameManagerContains/IGameManagerPtr.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"

#include <unordered_map>

//シーンインターフェイス
class Transition
{
public:
	// 遷移モード
	enum class Mode {
		In,
		Out
	};
	// 遷移のパラメータ
	struct Parametor {
		// 変化値
		float value;
		// 終了値
		float endValue;
	};
public:
	//コンストラクタ
	Transition(const IGameManagerPtr& gameManager);
	//デフォルトコンストラクタ
	//Transition();
	// 仮想デストラクタ     
	virtual ~Transition();
	// 開始     
	virtual void start();
	// 更新     
	virtual void update(float deltaTime);
	// 描画     
	virtual void draw()const;
	// モードの切りかえ
	void changeMode(const Mode& mode);
	// 終了フラグ
	virtual bool isEnd();

protected:
	// 開始     
	virtual void onStart();
	//更新
	virtual void onUpdate(float deltaTime);
	//描画
	virtual void onDraw() const;
protected:
	//ゲームマネージャー
	IGameManagerPtr p_GameManager;
	// テクスチャパラメータ
	Texture2DParameter m_Param;
	// モードパラメータ
	std::unordered_map<Mode, Parametor> mModeParametors;
	// 現在のモード
	Mode mMode;
	// 終了フラグ
	bool m_IsEnd;
};
