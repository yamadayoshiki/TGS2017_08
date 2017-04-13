#include "NullUI.h"

// �R���X�g���N�^
NullUI::NullUI(IWorld* world) : UI(world, UIName::None, GSvector2{ 0.0f, 0.0f }){}

// �R���X�g���N�^
NullUI::NullUI() : NullUI(nullptr){}

// �X�V����
void NullUI::onUpdate(float deltaTime){}

// �`�揈��
void NullUI::onDraw() const{}
