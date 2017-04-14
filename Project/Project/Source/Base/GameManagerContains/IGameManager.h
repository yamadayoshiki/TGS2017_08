#ifndef IGAMEMANAGER_H_
#define IGAMEMANAGER_H_

#include "../../Utility/Rederer2D/Renderer2D.h"

//ゲームマネージャーインターフェイス
class IGameManager
{
public:
	//仮想デストラクタ
	virtual ~IGameManager() 
	{
		Finalize();
	}
	//コンテンツの読み込み
	virtual void LoadContent() = 0;
	//コンテンツの削除
	virtual void UnLoadContent() = 0;

public:
	//レンダラーの取得
	virtual Renderer2D* GetRenderer2D() = 0;

protected:
	//終了処理
	virtual void Finalize() {};

};
#endif // !IGAMEMANAGER_H_
