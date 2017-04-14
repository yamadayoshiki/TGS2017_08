#ifndef RENDERER2D_H_
#define RENDERER2D_H_
#include <gslib.h>
#include <iostream>
#include <map>

#include"../../ActorContains/ActorName.h"

class Renderer2D
{
public:
	//コンストラクタ
	Renderer2D();

	//初期化
	void Initialize();

	//テクスチャ読み込み
	void LoadTexture(const std::string& fileName);

	//テクスチャ読み込み(fileName別登録)
	void LoadTexture
		(
			const std::string& texName,			//登録名
			const std::string& fileName			//ファイルパス
			);

	//テクスチャ描画
	void DrawTexture
		(
			const std::string& texName,		//登録名
			const GSrect& rect,				//描画範囲
			const GSvector2& position		//描画座標
			);

	//テクスチャ描画(パラメータ設定)...未実装
	//void DrawTexture
	//	(
	//		const std::string& texName,
	//		const TextureParameter2D& param
	//		);

	//エラー出力
	void ErrorPush(bool flag, const std::string& name);

	//コピー禁止
	Renderer2D& operator = (const Renderer2D& other) = delete;
	Renderer2D(const Renderer2D& other) = delete;

private:
	//指定した枚数目のrectを計算(アニメーションの補助)
	//GSrect CalculateAnimationRect
	//	(
	//		const GSrect& rect,		//切り取るテクスチャのrect
	//		int texWidth,			//テクスチャの横幅
	//		int texNum				//指定する枚数目
	//		);

private:
	std::map<std::string, unsigned int> m_TextureDic;
	unsigned int m_TextureID;
};

#endif