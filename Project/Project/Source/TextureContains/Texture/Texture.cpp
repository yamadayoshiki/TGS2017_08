#include "Texture.h"

Texture::Texture(
	const std::string & texName,
	const DrawManagerSPtr & drawManager,
	const DrawOrder drawOrder)
	: Texture_Base(texName, drawManager, drawOrder) {
}
