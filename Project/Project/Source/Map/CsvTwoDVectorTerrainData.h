#ifndef CSVTWODVECTORTERRAINDATA_H_
#define CSVTWODVECTORTERRAINDATA_H_

#include <vector>
enum class TerrainName;
using CsvRowTerrainData = std::vector<TerrainName>;
using CsvTwoDVectorTerrainData = std::vector<CsvRowTerrainData>;

#endif