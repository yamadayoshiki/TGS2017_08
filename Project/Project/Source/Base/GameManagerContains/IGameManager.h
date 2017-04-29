#ifndef IGAMEMANAGER_H_
#define IGAMEMANAGER_H_

#include "../../Utility/Rederer2D/Renderer2DPtr.h"
#include "../../Utility/InputState/InputStatePtr.h"

//ゲームマネージャーインターフェイス
class IGameManager
{
public:
	//仮想デストラクタ
	virtual ~IGameManager() {
		Finalize();
	}

public:
	//レンダラーの取得
	virtual  Renderer2DPtr GetRenderer2D() = 0;
	//インプットステイトの取得
	virtual InputStatePtr GetInputState() = 0;
	// シーンの終了の取得
	virtual bool IsEndScene() = 0;
	// シーンの終了
	virtual void EndScene(bool end) = 0;

protected:
	//終了処理
	virtual void Finalize() {};

};
#endif // !IGAMEMANAGER_H_
