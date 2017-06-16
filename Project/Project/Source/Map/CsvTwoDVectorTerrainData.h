#ifndef CSVTWODVECTORTERRAINDATA_H_
#define CSVTWODVECTORTERRAINDATA_H_

#include <vector>
enum class TerrainName;
using CsvColumTerrainData = std::vector<TerrainName>;
using CsvTwoDVectorTerrainData = std::vector<CsvColumTerrainData>;

#endif