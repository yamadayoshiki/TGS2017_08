#ifndef RENDERER2D_H_
#define RENDERER2D_H_
#include <gslib.h>
#include <iostream>
#include <map>

#include "../../ActorContains/ActorName.h"
#include "../Texture2DParameter/Texture2DParameterPtr.h"

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

	//テクスチャ破棄
	void UnLoadTexture();

	//テクスチャ破棄
	void UnLoadTexture(const std::string& texName);

	//テクスチャ描画
	void DrawTexture(
		const std::string& texName,				//登録名
		const GSvector2& pos);

	//テクスチャ描画(パラメータ設定)
	void DrawTexture(
		const std::string& texName,				//登録名
		const Texture2DParameter& parameter);	//パラメーター


	//テクスチャ描画(パラメータ設定)
	void DrawTexture(
		const std::string& texName,					//登録名
		const Texture2DParameterSPtr& parameter);	//パラメーター

	//指定のテクスチャIDの取得
	unsigned int GetTextureID(
		const std::string& texName);	//登録名

	//指定のテクスチャサイズの取得(登録名)
	GSrect* GetTextureRect(const std::string& texName);

	//エラー出力
	void ErrorPush(bool flag, const std::string& name);

	//コピー禁止
	Renderer2D& operator = (const Renderer2D& other) = delete;
	Renderer2D(const Renderer2D& other) = delete;

private:
	//テクスチャサイズの取得(登録名)
	GSvector2 GetTextureSize(const std::string& texName);

	//テクスチャサイズの取得(ID)
	GSvector2 GetTextureSize(const unsigned int textureID);

	//テクスチャサイズの登録
	void RecordTextureSize(const std::string& texName);

private:
	//登録名・ID
	std::map<std::string, unsigned int> m_TextureDic;
	unsigned int m_TextureID;

	//登録名・サイズ
	std::map<std::string, GSrect> m_TextureSizeDic;
};

#endif