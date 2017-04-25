#include"Map.h"
#include "../Utility/PathFinder/Point2.h"

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

//神保
// データの取得
int Map::operator [] (const Point2& position) const{
	return m_Map[position.y][position.x];
}
// 幅の取得
int Map::Width() const {
	return 17;
}

// 高さの取得
int Map::Height() const {
	return 13;
}