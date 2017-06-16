#include "UICreator.h"

#include "../UIFilePaths.h"
#include "../Button/Button.h"
#include "../Sprite/SpriteCreator.h"
#include "../../ActorContains/Transform/Transform.h"

UICreator::UICreator(IWorld * world, const IGameManagerPtr & gameManager, const UIFilePaths & path) :
	Actor(world, ActorName::UI_Manager, GSvector2({ 0.0f, 0.0f }), gameManager) {
	// �{�^���̐ݒ�i�݌v���_���Ȃ̂ŃR�[�h��ς����ق��������j
	addChild(std::make_shared<Button>(world, p_Transform->m_Position, gameManager, "Resource/StreamingAssets/UI/" + path.button));
	// �e�N�X�`���̐���
	addChild(std::make_shared<SpriteCreator>(world, p_Transform->m_Position, gameManager, "Resource/StreamingAssets/UI/" + path.sprite));
	// �ۗ�
	//addChild(std::make_shared<Button>(world, ActorName::Player, m_Transform.m_Position, gameManager, "Resource/StreamingAssets/UI/" + path.button));

}

