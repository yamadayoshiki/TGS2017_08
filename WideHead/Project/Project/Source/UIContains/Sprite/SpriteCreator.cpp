#include "SpriteCreator.h"

#include "Sprite.h"
#include "../../FileReader/CsvReader.h"
#include "../../TextureContains/Texture/Texture.h"
#include "../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
// コンストラクタ
SpriteCreator::SpriteCreator(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name) :
	Actor(world, ActorName::None, position, gameManager) {
	// 生成
	create(file_name);
}

// 生成
void SpriteCreator::create(const std::string & file_name)
{
	// csv読み込み
	CsvReader csv = CsvReader(file_name);

	// 行のループ(0行目は要素の説明なので "row = 1" から)
	for (int row = 1; row < csv.rows(); row++) {
		// テクスチャのパス&名前
		std::string name = csv.get(row, static_cast<int>(Element::NAME));
		// Textureの宣言
		ITexturePtr texture;

		// アニメーションするかしないかで分岐
		// アニメーションしない場合
		if (csv.geti(row, static_cast<int>(Element::ANIMATE)) == 0) {
			texture = std::make_shared<Texture>(name, p_GameManager->GetDrawManager(), (DrawOrder)csv.geti(row, static_cast<int>(Element::DRAWORDER)));
		}
		// アニメーションする場合
		else {
			texture = std::make_shared<AnimationTexture>(name, p_GameManager->GetDrawManager(), DrawOrder::UI, csv.geti(row, static_cast<int>(Element::WIDTH)), csv.geti(row, static_cast<int>(Element::TIME)));
		}
		// 透明度の設定
		//texture->GetParameter()->m_Color = { 1,1,1, csv.getf(row, static_cast<int>(Element::ALPHA)) };
		// Spriteの生成
		addChild(std::make_shared<Sprite>(p_World, p_GameManager, (DrawOrder)csv.geti(row, static_cast<int>(Element::DRAWORDER)), GSvector2(csv.getf(row, static_cast<int>(Element::POS_X)), csv.getf(row, static_cast<int>(Element::POS_Y))), texture, csv.get(row, static_cast<int>(Element::USAGE))));
	}
}

