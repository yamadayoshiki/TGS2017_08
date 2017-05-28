#include "SpriteCreator.h"

#include "Sprite.h"
#include "../../FileReader/CsvReader.h"
#include "../../TextureContains/Base/Texture_Base.h"
#include "../../Utility/Animation/Animation.h"
#include "../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"

// �R���X�g���N�^
SpriteCreator::SpriteCreator(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name) :
	Actor(world, ActorName::UI_Sprite, position, gameManager) {
	// ����
	create(file_name);
}

// ����
void SpriteCreator::create(const std::string & file_name)
{
	// csv�ǂݍ���
	CsvReader csv = CsvReader(file_name);

	// �s�̃��[�v(0�s�ڂ͗v�f�̐����Ȃ̂� "row = 1" ����)
	for (int row = 1; row < csv.rows(); row++) {
		// �e�N�X�`���̃p�X&���O
		std::string name = "Resource/Texture/UI/" + csv.get(row, static_cast<int>(Element::NAME));
		// �e�N�X�`���̓ǂݍ���
		p_GameManager->GetRenderer2D()->LoadTexture(name, name);
		// Texture�̐錾
		std::shared_ptr<Texture_Base> texture;

		// �A�j���[�V�������邩���Ȃ����ŕ���
		// �A�j���[�V�������Ȃ��ꍇ
		if (csv.geti(row, static_cast<int>(Element::ANIMATE)) == 0) {
			texture = std::make_shared<Texture_Base>(name, p_GameManager->GetRenderer2D());
		}
		// �A�j���[�V��������ꍇ
		else {
			texture = std::make_shared<AnimationTexture>(name, p_GameManager->GetRenderer2D(), new Animation(*p_GameManager->GetRenderer2D()->GetTextureRect(name), csv.geti(row, static_cast<int>(Element::WIDTH)), csv.geti(row, static_cast<int>(Element::TIME))));
		}
		// �����x�̐ݒ�
		//texture->GetParameter()->SetColor({ 1,1,1, csv.getf(row, static_cast<int>(Element::ALPHA)) });
		// Sprite�̐���
		addChild(std::make_shared<Sprite>(p_World, p_GameManager, GSvector2(csv.getf(row, static_cast<int>(Element::POS_X)), csv.getf(row, static_cast<int>(Element::POS_Y))), texture));
	}
}

