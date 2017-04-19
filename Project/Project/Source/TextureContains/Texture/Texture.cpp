#include "Texture.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"

//コンストラクタ
Texture::Texture(
	const std::string& texName,
	Renderer2D* renderer)
	:Texture_Base(texName, renderer) {}

//初期化
void Texture::OnInitialize() {
}

//更新
void Texture::Update(float deltaTime) {
}