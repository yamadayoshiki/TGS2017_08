#ifndef MAP_H_
#define MAP_H_

#include"../Utility/Rederer2D/Renderer2DPtr.h"
#include"../Tile/Tile.h"
#include"../Tile/TileData.h"

#include<iostream>
#include <vector>
#include<unordered_map>

//グリッド座標
class Point2;

class Map
{
public:
	
	//マップの取得
	std::vector<std::vector<int>>& getmap();
	//周りのタイルデータの取得
	std::unordered_map<Tile, TileData>GetAroundTile (const GSvector2& position);
	//タイルデータの取得
	TileData GetTileData(int x, int y);

	//神保
public:
	// データの取得
	int operator [] (const Point2& position) const;
	// 幅の取得
	int Width() const;
	// 高さの取得
	int Height() const;
	
private:
	Renderer2DPtr p_Renderer2D;
	std::vector<std::vector<int>> m_Map;
};

#endif // !MAP_H_