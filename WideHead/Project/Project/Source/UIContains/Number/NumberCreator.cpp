#include "NumberCreator.h"
#include "Number.h"
#include "../../FileReader/CsvReader.h"
#include "../../TextureContains/NumberTexture/NumberTexture.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"

NumberCreator::NumberCreator(
	IWorld * world,
	const GSvector2 & position,
	const IGameManagerPtr & gameManager,
	const std::string & file_name)
	: Actor(world, ActorName::None, position, gameManager) {
	//����
	Create(file_name);
}

void NumberCreator::Create(const std::string & file_name) {
	// csv�ǂݍ���
	CsvReader csv = CsvReader(file_name);
	// �s�̃��[�v(0�s�ڂ͗v�f�̐����Ȃ̂� "row = 1" ����)
	for (int row = 1; row < csv.rows(); row++) {
		// �e�N�X�`���̃p�X&���O
		std::string name = csv.get(row, static_cast<int>(Element::NAME));
		// Number�̐���
		addChild(
			std::make_shared<Number>(
				p_World,
				p_GameManager,
				(DrawOrder)csv.geti(row, static_cast<int>(Element::DRAWORDER)),
				std::make_shared<NumberTexture>(
					name,
					p_GameManager->GetDrawManager(),
					(DrawOrder)csv.geti(row, static_cast<int>(Element::DRAWORDER)),
					GSvector2(
						csv.getf(row, static_cast<int>(Element::POS_X)),
						csv.getf(row, static_cast<int>(Element::POS_Y))),
					csv.getf(row, static_cast<int>(Element::LENGTH))),
				csv.get(row, static_cast<int>(Element::USAGE))));

	}
}
