#ifndef NUMBER_TEXTURE_H_
#define NUMBER_TEXTURE_H_

#include <gslib.h>
#include <string>
class NumberTexture
{
public:
	NumberTexture(GSint texture, int width, int height);
	void draw(const GSvector2& position, int num, int digit, char fill = '0')const;
	void draw(const GSvector2& position, int num) const;
	void draw(const GSvector2& position, const std::string& num)const;

private:
	GSint mTexure;
	//•¶š‚Ì•
	int mWidth;
	//•¶š‚Ì‚‚³
	int mHeight;

};
#endif // !NUMBER_TEXTURE_H_

#pragma once
