#ifndef IGAMEMANAGER_H_
#define IGAMEMANAGER_H_

class Renderer2D;
class InputState;

//ゲームマネージャーインターフェイス
class IGameManager
{
public:
	//仮想デストラクタ
	virtual ~IGameManager() {
		Finalize();
	}
	//コンテンツの読み込み
	virtual void LoadContent() = 0;
	//コンテンツの削除
	virtual void UnLoadContent() = 0;

public:
	//レンダラーの取得
	virtual Renderer2D* GetRenderer2D() = 0;
	//インプットステイトの取得
	virtual InputState* GetInputState() = 0;
protected:
	//終了処理
	virtual void Finalize() {};

};
#endif // !IGAMEMANAGER_H_
