#ifndef COMBO_H_
#define COMBO_H_

#include"../Base/UI_Base.h"
#include<vector>
#include"../../TextureContains/ITexturePtr.h"

class Combo :public UI_Base
{
public:
	Combo(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);
	void regist(const std::string & file_name);

private:
	virtual void onUpdate(float deltaTime)override;
	virtual void onDraw()const override;
	void setTexture();

private:
	Renderer2DPtr	p_Renderer2D;
	using TextureList = std::vector<ITexturePtr>;
	TextureList	 m_TextureList;
	float weidth{ 0.0f };

};
#endif // !COMBO_H_
