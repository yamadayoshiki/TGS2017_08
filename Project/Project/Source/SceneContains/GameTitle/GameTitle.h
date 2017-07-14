#ifndef GAMETITLE_H_
#define GAMETITLE_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include <iostream>
class AnimationTexture;
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
	virtual void OnEnd()override;

private:
	//タイトルの動き
	void TitleMove();

private:
	float TitleSpeed = -600;					//タイトルの初期位置
	float m_TitleFraemConter;					//フレーム数

	Texture2DParameterSPtr p_Title;				//タイトル背景
	Texture2DParameterSPtr p_WideHead;			//タイトルロゴ
	Texture2DParameterSPtr p_Start;				//スタート
	AnimationTexture* p_AnimationTexture;		//アニメーションテクスチャ

	int m_TitleNum;
	int m_WideHeadNum;
	int m_StartNum;
};

#endif