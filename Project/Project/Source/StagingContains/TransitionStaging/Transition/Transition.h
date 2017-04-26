#pragma once

#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"

//シーンインターフェイス
class Transition
{
public:
	//コンストラクタ
	Transition(Texture2DParameter* parameter);
	//デフォルトコンストラクタ
	//Transition();
	// 仮想デストラクタ     
	virtual ~Transition();
	// 開始     
	virtual void start();
	// 更新     
	virtual void update(float deltaTime);

protected:
	//更新
	virtual void onUpdate(float deltaTime);
	//描画
	virtual void onDraw() const;

protected:
	bool m_IsEnd;					//終了フラグ
	//IGameManager* p_GameManager;	//ゲームマネージャー
};
