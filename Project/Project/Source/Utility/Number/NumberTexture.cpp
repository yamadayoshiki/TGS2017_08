#include "NumberTexture.h"
#include <sstream>
#include <iomanip>

using namespace std;

NumberTexture::NumberTexture(GSint texture, int width, int height)
	:mTexure(texture),mWidth(width),mHeight(height)
{
}

void NumberTexture::draw(const GSvector2 & position, int num, int digit, char fill) const
{
	stringstream ss;
	ss << setw(digit) << setfill(fill) << num;
	draw(position, ss.str());
}

void NumberTexture::draw(const GSvector2 & position, int num) const
{
	draw(position, to_string(num));
}

void NumberTexture::draw(const GSvector2& position, const std::string& num) const
{
	for (int i = 0; i < (int)num.size(); i++)
	{
		if (num[i] == ' ')continue;
		const int n = num[i] - '0';
		const GSrect rect(n*mWidth, 0.0f, (n*mWidth) + mWidth, mHeight);
		const GSvector2 pos(position.x + i * mWidth, position.y);
		gsDrawSprite2D(mTexure, &pos, &rect, NULL, NULL, NULL, 0);
	}
}
