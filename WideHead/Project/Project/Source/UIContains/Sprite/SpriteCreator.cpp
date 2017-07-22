#include "SpriteCreator.h"

#include "Sprite.h"
#include "../../FileReader/CsvReader.h"
#include "../../TextureContains/Texture/Texture.h"
#include "../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
// �R���X�g���N�^
SpriteCreator::SpriteCreator(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name) :
	Actor(world, ActorName::None, position, gameManager) {
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
		std::string name = csv.get(row, static_cast<int>(Element::NAME));
		// Texture�̐錾
		ITexturePtr texture;

		// �A�j���[�V�������邩���Ȃ����ŕ���
		// �A�j���[�V�������Ȃ��ꍇ
		if (csv.geti(row, static_cast<int>(Element::ANIMATE)) == 0) {
			texture = std::make_shared<Texture>(name, p_GameManager->GetDrawManager(), (DrawOrder)csv.geti(row, static_cast<int>(Element::DRAWORDER)));
		}
		// �A�j���[�V��������ꍇ
		else {
			texture = std::make_shared<AnimationTexture>(name, p_GameManager->GetDrawManager(), DrawOrder::UI, csv.geti(row, static_cast<int>(Element::WIDTH)), csv.geti(row, static_cast<int>(Element::TIME)));
		}
		// �����x�̐ݒ�
		//texture->GetParameter()->m_Color = { 1,1,1, csv.getf(row, static_cast<int>(Element::ALPHA)) };
		// Sprite�̐���
		addChild(std::make_shared<Sprite>(p_World, p_GameManager, (DrawOrder)csv.geti(row, static_cast<int>(Element::DRAWORDER)), GSvector2(csv.getf(row, static_cast<int>(Element::POS_X)), csv.getf(row, static_cast<int>(Element::POS_Y))), texture, csv.get(row, static_cast<int>(Element::USAGE))));
	}
}

