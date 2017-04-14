#ifndef ISCENE_H_
#define ISCENE_H_

enum class SceneName;

//シーン抽象インターフェイス
class IScene
{
public:
	// 仮想デストラクタ     
	virtual ~IScene() {}
	// 開始     
	virtual void Start() = 0;
	// 更新     
	virtual void Update(float deltaTime) = 0;
	// 描画     
	virtual void Draw() const = 0;
	// 終了しているか？     
	virtual bool IsEnd() const = 0;
	// 次のシーンを返す     
	virtual SceneName Next() const = 0;
	// 終了     
	virtual void End() = 0;
};



#endif