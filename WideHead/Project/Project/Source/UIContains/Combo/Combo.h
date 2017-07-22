#ifndef COMBO_H_
#define COMBO_H_

#include"../Base/UI_Base.h"
#include<vector>
#include"../../TextureContains/ITexturePtr.h"
#include"../../Utility/Texture2DParameter/Texture2DParameter.h"
class NumberTexture;
class Combo :public UI_Base
{
public:
	Combo(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);
	void regist(const std::string & file_name);

private:
	virtual void onUpdate(float deltaTime)override;
	virtual void onDraw()const override;
	void setTexture();
public:
	void ChangeDisplayMode(const DisplayMode mode)override;
private:
	using TextureList = std::vector<ITexturePtr>;
	TextureList	 m_TextureList;
	float weidth{ 300.0f };
	float m_NowTime;
	float m_MaxTime{ 180.0f };

	std::shared_ptr<NumberTexture> p_NumberTexture;
};
#endif // !COMBO_H_
