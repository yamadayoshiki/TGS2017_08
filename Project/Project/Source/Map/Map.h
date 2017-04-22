#ifndef MAP_H_
#define MAP_H_

#include"../Utility/Rederer2D/Renderer2DPtr.h"

#include<iostream>
#include <vector>

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
	
private:
	Renderer2DPtr p_Renderer2D;
	std::vector<std::vector<int>> m_Map;
};

#endif // !MAP_H_