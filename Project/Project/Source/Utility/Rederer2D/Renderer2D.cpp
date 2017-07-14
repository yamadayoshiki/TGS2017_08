#include "Renderer2D.h"
#include <cassert>
#include <gslib.h>
#include "../Texture2DParameter/Texture2DParameter.h"

//コンストラクタ
Renderer2D::Renderer2D()
	:m_TextureID(0) {
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
void Renderer2D::LoadTexture(const std::string& fileName) {
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
//テクスチャ破棄
void Renderer2D::UnLoadTexture() {
	for (auto texture = m_TextureDic.begin(); texture != m_TextureDic.end(); texture++)
		gsDeleteTexture((*texture).second);

	m_TextureDic.clear();
}

//テクスチャ破棄
void Renderer2D::UnLoadTexture(const std::string & texName) {
	//登録されているか
	auto itr = m_TextureDic.find(texName);
	if (itr == m_TextureDic.end())
		return;

	//破棄
	gsDeleteTexture((*itr).second);
	m_TextureDic.erase(itr);
}

void Renderer2D::DrawTexture(const std::string & texName, const GSvector2 & pos) {
	gsDrawSprite2D(
		m_TextureDic[texName],
		&pos,
		&GSrect(0, 0, GetTextureSize(texName).x, GetTextureSize(texName).y),
		&GSvector2(0.0f, 0.0f),
		&GScolor(1.0f, 1.0f, 1.0f, 1.0f),
		&GSvector2(1.0f, 1.0f),
		0);
}

//テクスチャ描画(パラメータ設定)
void Renderer2D::DrawTexture(
	const std::string& texName,				//登録名
	const Texture2DParameter& parameter) {	//パラメーター
	gsDrawSprite2D(
		m_TextureDic[texName],
		&parameter.m_Position,
		&parameter.m_Rect,
		&parameter.m_Center,
		&parameter.m_Color,
		&parameter.m_Scale,
		parameter.m_Rotate);
}

//テクスチャ描画(パラメータ設定)
void Renderer2D::DrawTexture(
	const std::string & texName,
	const Texture2DParameterSPtr & parameter) {
	DrawTexture(texName, *parameter.get());
}

//指定のテクスチャIDの取得
unsigned int Renderer2D::GetTextureID(
	const std::string& texName	//登録名
	)
{
	return m_TextureDic[texName];
}

//指定のテクスチャサイズの取得(登録名)
GSrect* Renderer2D::GetTextureRect(const std::string& texName)
{
	return &m_TextureSizeDic[texName];
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

//テクスチャサイズの取得(登録名)
GSvector2 Renderer2D::GetTextureSize(const std::string& texName)
{
	return GetTextureSize(m_TextureDic[texName]);
}

//テクスチャサイズの取得(ID)
GSvector2 Renderer2D::GetTextureSize(const unsigned int textureID)
{
	GSvector2 result = GSvector2();
	result.x = gsTextureGetWidth(gsGetTexture(textureID));
	result.y = gsTextureGetHeight(gsGetTexture(textureID));

	return result;
}

//テクスチャサイズの登録
void Renderer2D::RecordTextureSize(const std::string& texName)
{
	GSvector2 size = GetTextureSize(texName);
	GSrect rectSize;
	rectSize.right = size.x;
	rectSize.bottom = size.y;
	m_TextureSizeDic[texName] = rectSize;
}
