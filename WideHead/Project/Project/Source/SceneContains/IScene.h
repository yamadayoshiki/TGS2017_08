#ifndef ISCENE_H_
#define ISCENE_H_

#include "SceneName.h"
#include <vector>
enum class SceneMode;
class ChildScene;
enum class EventMessage;

//シーン抽象インターフェイス
class IScene
{
public:
	// 仮想デストラクタ     
	virtual ~IScene() {}
	// セットアップ
	virtual void SetUp() = 0;
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
	// 名前の設定
	virtual void SetName(const SceneName& name) = 0;
	// 名前の取得
	virtual SceneName GetName() = 0;
	// 子の設定
	virtual void SetUpChild(ChildScene& child) = 0;
	// メッセージ処理
	virtual void HandleMessage(EventMessage message, void* param) = 0;
	// ワールドの停止
	virtual void StopWorld() = 0;
	// ワールドの再開
	virtual void Restart() = 0;
	// 兄弟配列の設定
	virtual void SetBrothers(const std::vector<SceneName>& children) = 0;
};



#endif