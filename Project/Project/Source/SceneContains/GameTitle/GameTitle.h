#ifndef GAMETITLE_H_
#define GAMETITLE_H_

#include "../Scene/Scene.h"
#include"../../TextureContains/AnimationTexture/AnimationTexture.h"
//タイトルシーン
class GameTitle : public Scene
{
public:
	// コンストラクタ    
	GameTitle(const IGameManagerPtr& gameManager);
	//デストラクタ
	~GameTitle();
	//テクスチャ・アニメーションの名前の設定
	void setName_TitleAnimation(const std::string& name);
	//アニメーションのループ回数を取得
	unsigned int GetLoopTitleCount();

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
	// 描画     
	virtual void OnDraw()const;
	//終了
	virtual void End()override;

private:
	//タイトルの初期位置
	float TitleSpeed = -600;
	//タイトルの動き
	void TitleMove();
	//レンダラー
	Renderer2DPtr			p_Renderer;
	//アニメーションテクスチャ
	AnimationTexture* p_AnimationTexture;
	//アニメーション
	Animation*				m_Animation;
	//フレーム数
	float					m_TitleFraemConter;
	//名前
	std::string				m_TitleName,m_TitleName2;
};

#endif