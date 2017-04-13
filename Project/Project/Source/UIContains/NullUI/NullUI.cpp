#include "NullUI.h"

// コンストラクタ
NullUI::NullUI(IWorld* world) : UI(world, UIName::None, GSvector2{ 0.0f, 0.0f }){}

// コンストラクタ
NullUI::NullUI() : NullUI(nullptr){}

// 更新処理
void NullUI::onUpdate(float deltaTime){}

// 描画処理
void NullUI::onDraw() const{}
