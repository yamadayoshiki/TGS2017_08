#ifndef MAP_GENERATOR_H_
#define MAP_GENERATOR_H_

#include<string>

class MapGenerator
{
public:
	//コンストラクタ
	MapGenerator(const std::string& file_name);
	//ファイルの読み込み
	void load(const std::string& file_name);
private:

};

#endif // !MAP_GENERATOR_H_