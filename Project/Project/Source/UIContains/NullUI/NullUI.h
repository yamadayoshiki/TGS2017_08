#ifndef NULL_UI_H_
#define NULL_UI_H_

#include "../UI/UI.h"

// NullUIクラス
class NullUI :public UI{
public:
	// コンストラクタ
	NullUI(IWorld* world);
	// コンストラクタ
	NullUI();

	// 更新処理
	virtual void onUpdate(float deltaTime) override;
	// 描画処理
	virtual void onDraw() const override;
};

#endif // !NULL_UI_H_
