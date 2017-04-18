#include "Renderer2D.h"
#include <cassert>
#include <gslib.h>
#include "../Texture2DParameter/Texture2DParameter.h"

//コンストラクタ
Renderer2D::Renderer2D()
	:m_TextureID(0)
{
	m_TextureDic.clear();
	m_TextureSizeDic.clear();
}

//初期化
void Renderer2D::Initialize()
{
	m_TextureID = 0;
	m_TextureDic.clear();
	m_TextureSizeDic.clear();
}

//テクスチャ読み込み
void Renderer2D::LoadTexture(const std::string& fileName)
{
	LoadTexture(fileName, fileName);
}

//テクスチャ読み込み(fileName別登録)
void Renderer2D::LoadTexture(
	const std::string& texName,			//登録名
	const std::string& fileName			//ファイルパス
	)
{
	//テクスチャー読み込み
	m_TextureDic[texName] = m_TextureID;
	bool flag = (gsLoadTexture(m_TextureDic[texName], fileName.c_str()) == GS_TRUE);
	RecordTextureSize(texName);
	m_TextureID++;

	ErrorPush(flag, texName);
}

//テクスチャ描画
void Renderer2D::DrawTexture(
	const std::string& texName,										//登録名
	const GSvector2& position)										//描画座標
{
	gsDrawSprite2D
		(
			m_TextureDic[texName],
			&position,
			m_TextureSizeDic[texName],
			NULL,
			NULL,
			NULL,
			0.0f);
}

//テクスチャ描画(パラメータ設定)
void Renderer2D::DrawTexture
(
	const std::string& texName,				//登録名
	const Texture2DParameter& parameter		//パラメーター
	)
{
	gsDrawSprite2D(
		m_TextureDic[texName],
		&parameter.GetPosition(),
		&parameter.GetRect(),
		&parameter.GetCenter(),
		&parameter.GetColor(),
		&parameter.GetScale(),
		parameter.GetRotate()
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

//指定した枚数目のrectを計算(アニメーションの補助)
GSrect Renderer2D::CalculateAnimationRect(
	const GSrect& rect,		//切り取るテクスチャのrect
	int texWidth,			//テクスチャの横幅
	int texNum				//指定する枚数目
	)
{
	//枚数を座標の計算に置き換える為
	texNum -= 1;

	//テクスチャの幅と高さ
	const int texCutWidth = rect.right - rect.left;
	const int texCutHeight = rect.bottom - rect.top;

	//テクスチャの大きさから横に何分割するか決める
	const int cutX = texWidth / rect.right;

	//テクスチャの左上座標
	const GSvector2 texCoord
		(
			(texNum % cutX) * texCutWidth,
			(texNum / cutX) * texCutHeight
			);

	//テクスチャから切り取る四角形
	const GSrect result = GSrect
		(
			texCoord.x,
			texCoord.y,
			texCoord.x + texCutWidth,
			texCoord.y + texCutHeight
			);

	return result;
}

//テクスチャサイズの取得(登録名)
GSvector2 Renderer2D::GetTextureSize(const std::string& texName)
{
	return GetTextureSize(m_TextureDic[texName]);
}

//テクスチャサイズの取得(ID)
GSvector2 Renderer2D::GetTextureSize(const unsigned int textureID)
{
	GSvector2 result = GSvector2();
	GStexture* tex = gsGetTexture(textureID);
	result.x = gsTextureGetWidth(tex);
	result.y = gsTextureGetHeight(tex);

	return result;
}

//テクスチャサイズの登録
void Renderer2D::RecordTextureSize(const std::string& texName)
{
	GSvector2 size = GetTextureSize(texName);
	GSrect* rectSize = new GSrect();
	rectSize->right = size.x;
	rectSize->bottom = size.y;
	m_TextureSizeDic[texName] = rectSize;
}