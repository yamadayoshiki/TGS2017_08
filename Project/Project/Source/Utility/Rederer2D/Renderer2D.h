#ifndef RENDERER2D_H_
#define RENDERER2D_H_
#include <gslib.h>
#include <iostream>

#include"../../ActorContains/ActorName.h"

class Renderer2D
{
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

	void DrawTexture
		(
			const std::string& texName//,
			//const TextureParameter2D& param
			);

private:
	//指定した枚数目のrectを計算
	GSrect CalculateAnimationRect
		(
			const GSrect& rect,		//切り取るテクスチャのrect
			int texWidth,			//テクスチャの横幅
			int texNum				//指定する枚数目
			);

	//コピー禁止
	Renderer2D& operator = (const Renderer2D& other) = delete;
	Renderer2D(const Renderer2D& other) = delete;
};

#endif