#include"Map.h"
#include "../Utility/PathFinder/Point2.h"
#include"../Define/Def_Nakayama.h"
#include"../Base/GameManagerContains/GameManager/GameManager.h"
#include"../Utility/Rederer2D/Renderer2D.h"

//コンストラクタ
Map::Map(const IGameManagerPtr& gameManager):
	p_GameManager(gameManager)
{
	p_GameManager->GetRenderer2D()->LoadTexture("chip", "Resource/Texture/wall.png");
}
//描画
void Map::draw()
{
	// 行のループ
	for (int i = 0;i < m_Map.size(); i++)
	{
		// 列のループ
		for (int j = 0; j < m_Map[i].size(); j++)
		{
			if (m_Map[i][j] == 1)
			{
				//gsTextPos(j * CHIP_SIZE, i * CHIP_SIZE);
				p_GameManager->GetRenderer2D()->DrawTexture("chip", GSvector2(j, i)* CHIP_SIZE);
			}
		}
	}
}

//マップの取得
std::vector<std::vector<int>>& Map::getmap()
{
	return m_Map;
}
//周りのタイルデータの取得
std::unordered_map<Tile, TileData> Map::GetAroundTile(const GSvector2& position)
{
	int x = position.x / CHIP_SIZE;
	int y = position.y / CHIP_SIZE;

	TileData left = GetTileData(x -1,y);
	TileData right = GetTileData(x + 1,y);
	TileData top = GetTileData(x,y -1);
	TileData down = GetTileData(x,y +1);
	
	std::unordered_map<Tile, TileData> datas;

	datas[Tile::Left] = left;
	datas[Tile::Right] = right;
	datas[Tile::Top] = top;
	datas[Tile::Down] = down;

	return datas;
}

//指定された座標の縦軸のブロックの取得
std::vector<int> Map::GetRow(const GSvector2 & position){
	int x = position.x / CHIP_SIZE;
	
	std::vector<int> tmp;
	
	for (int i = 0; i < m_Map.size(); i++) {
		tmp.push_back(m_Map[i][x]);
	}

	return tmp;
}

//指定された座標の横軸のブロックの取得
std::vector<int> Map::GetColumn(const GSvector2 & position){
	int y = position.y / CHIP_SIZE;

	return m_Map[y];
}

//タイルデータの取得
TileData Map::GetTileData(int x, int y)
{
	TileData result;

	result.position = GSvector2(x, y) * CHIP_SIZE;
	result.rectangle = GSrect(0, 0, CHIP_SIZE, CHIP_SIZE);
	result.flag = m_Map[y][x];

	return result;
}

//神保
// データの取得
int Map::operator [] (const Point2& position) const{
	return m_Map[position.y][position.x];
}
// 幅の取得
int Map::Width() const {
	return m_Map[0].size();
}

// 高さの取得
int Map::Height() const {
	return m_Map.size();
}