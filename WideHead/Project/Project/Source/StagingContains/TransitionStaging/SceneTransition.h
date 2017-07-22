#ifndef SCENETRANSITION_H_
#define SCENETRANSITION_H_
#include "Transition/Transition.h"
#include <gslib.h>
class Texture;
// シーン切り替えクラス
class SceneTransition : public Transition {
public:
	// コンストラクタ
	SceneTransition(const IGameManagerPtr& gameManager);
	// デストラクタ
	~SceneTransition();

	// 開始     
	virtual void onStart()override;
	//更新
	virtual void onUpdate(float deltaTime)override;
	//描画
	virtual void onDraw() const override;
	// 終了
	virtual void onEnd() override;
	// 終了フラグ
	virtual bool isEnd() override;
private:
	GScolor m_Color;	// α値
	std::shared_ptr<Texture> p_Texture;
};

#endif // !SCENETRANSITION_H_