#ifndef NUMBER_H_
#define NUMBER_H_
#include "../Base/UI_Base.h"
class NumberTexture;
//UINumbr
class Number : public UI_Base {
public:
	//コンストラクタ
	Number(
		IWorld* world,							//ワールド
		const IGameManagerPtr& gameManager,		//ゲームマネージャ
		const DrawOrder drawOrder,				//描画順序
		const ITexturePtr& texture,				//テクスチャ
		const std::string& usage);				//用途

public:
	void ChangeDisplayMode(const DisplayMode mode) override;

public:
	//用途の取得
	std::string GetUsage() const;
	//番号設定
	void SetNum(const int num);


private:
	std::shared_ptr<NumberTexture> p_NumberTexture;		//数字テクスチャ
	std::string m_Usage;								//用途
};
#endif // !NUMBER_H_
