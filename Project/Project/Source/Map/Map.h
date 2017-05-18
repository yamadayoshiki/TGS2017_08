#ifndef MAP_H_
#define MAP_H_

#include"../Utility/Rederer2D/Renderer2DPtr.h"
#include"../Utility/FourDirection/FourDirection.h"
#include"../Tile/TileData.h"
#include "../ActorContains/ActorPtr.h"
#include "../Base/GameManagerContains/IGameManagerPtr.h"

#include<iostream>
#include <vector>
#include<unordered_map>

//グリッド座標
class Point2;

class Map
{
public:

	//コンストラクタ
	Map(const IGameManagerPtr& gameManager);
	//描画
	void draw();
	//マップの取得
	std::vector<std::vector<int>>& getmap();
	//周りのタイルデータの取得
	std::unordered_map<FourDirection, TileData>GetAroundTile(const GSvector2& position);
	//指定された座標の縦軸のブロックの取得
	std::vector<int>GetRow(const GSvector2& position);
	//指定された座標の横軸のブロックの取得
	std::vector<int>GetColumn(const GSvector2& position);
	//タイルデータの取得
	TileData GetTileData(int x, int y);
	// 正面に壁があるか無いか
	bool IsInFrontOfTheWall(const GSvector2& pos, FourDirection direction);
	//神保
public:
	// データの取得
	int operator [] (const Point2& position) const;
	// 幅の取得
	int GetWidth() const;
	// 高さの取得
	int GetHeight() const;

private:
	Renderer2DPtr p_Renderer2D;
	std::vector<std::vector<int>> m_Map;
	//ゲームマネージャーポインタ
	IGameManagerPtr p_GameManager;
};

#endif // !MAP_H_