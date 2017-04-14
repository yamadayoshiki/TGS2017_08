#include "Renderer2D.h"
#include <cassert>
#include <gslib.h>

//コンストラクタ
Renderer2D::Renderer2D()
	:m_TextureID(0)
{
	m_TextureDic.clear();
}

//初期化
void Renderer2D::Initialize()
{
	m_TextureID = 0;
	m_TextureDic.clear();
}

//テクスチャ読み込み
void Renderer2D::LoadTexture(const std::string& fileName)
{
	LoadTexture(fileName, fileName);
}

//テクスチャ読み込み(fileName別登録)
void Renderer2D::LoadTexture
(
	const std::string& texName,			//登録名
	const std::string& fileName			//ファイルパス
	)
{
	//テクスチャー読み込み
	m_TextureDic[texName] = m_TextureID;
	bool flag = (gsLoadTexture(m_TextureDic[texName], fileName.c_str()) == GS_TRUE);
	m_TextureID++;

	ErrorPush(flag, texName);
}

//テクスチャ描画
void Renderer2D::DrawTexture
(
	const std::string& texName,		//登録名
	const GSrect& rect,				//描画範囲
	const GSvector2& position		//描画座標
	)
{
	gsDrawSprite2D
		(
			m_TextureDic[texName],
			&position,
			&rect,
			NULL,
			NULL,
			NULL,
			0.0f
			);
}

//エラー出力
void Renderer2D::ErrorPush(bool flag, const std::string& name)
{
	//ファイルが存在しない場合にエラーを出力
	//GSLoadからのBoolの戻り値を利用する
	if (flag == false)
	{
		//存在しなかったファイル名
		printf(name.c_str());
		printf("\n");
		//Assert文でプログラム停止
		assert(!"No File Found");
	}
}