#ifndef MAP_H_
#define MAP_H_

#include"../Utility/Rederer2D/Renderer2DPtr.h"

#include<iostream>
#include <vector>

//グリッド座標
class Point2;

class Map
{

public:
	//コンストラクタ
	Map();
	//ロード
	void Load();
	//アンロード
	void Unload();
	//更新
	void Update(float deltaTime);
	//描画
	void Draw() const;
	//衝突判定
	void Collide();
	//マップの取得
	std::vector<std::vector<int>> getmap();

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