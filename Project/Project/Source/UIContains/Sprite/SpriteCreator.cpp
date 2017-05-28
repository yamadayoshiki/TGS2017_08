#include "SpriteCreator.h"

#include "Sprite.h"
#include "../../FileReader/CsvReader.h"
#include "../../TextureContains/Base/Texture_Base.h"
#include "../../Utility/Animation/Animation.h"
#include "../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"

// コンストラクタ
SpriteCreator::SpriteCreator(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name) :
	Actor(world, ActorName::UI_Sprite, position, gameManager) {
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
		std::string name = "Resource/Texture/UI/" + csv.get(row, static_cast<int>(Element::NAME));
		// テクスチャの読み込み
		p_GameManager->GetRenderer2D()->LoadTexture(name, name);
		// Textureの宣言
		std::shared_ptr<Texture_Base> texture;

		// アニメーションするかしないかで分岐
		// アニメーションしない場合
		if (csv.geti(row, static_cast<int>(Element::ANIMATE)) == 0) {
			texture = std::make_shared<Texture_Base>(name, p_GameManager->GetRenderer2D());
		}
		// アニメーションする場合
		else {
			texture = std::make_shared<AnimationTexture>(name, p_GameManager->GetRenderer2D(), new Animation(*p_GameManager->GetRenderer2D()->GetTextureRect(name), csv.geti(row, static_cast<int>(Element::WIDTH)), csv.geti(row, static_cast<int>(Element::TIME))));
		}
		// 透明度の設定
		//texture->GetParameter()->SetColor({ 1,1,1, csv.getf(row, static_cast<int>(Element::ALPHA)) });
		// Spriteの生成
		addChild(std::make_shared<Sprite>(p_World, p_GameManager, GSvector2(csv.getf(row, static_cast<int>(Element::POS_X)), csv.getf(row, static_cast<int>(Element::POS_Y))), texture));
	}
}

