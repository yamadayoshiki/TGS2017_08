#include"Map.h"

//コンストラクタ
Map::Map()
{

}
//ロード
void Map::Load()
{
}
//アンロード
void Map::Unload()
{
}
//更新
void Map::Update(float deltaTime)
{
}
//描画
void Map::Draw() const
{
}
//衝突判定
void Map::Collide()
{
}

std::vector<std::vector<int>> Map::getmap()
{
	return m_Map;
}

