#ifndef MAPGENERATOR_PTR_H_
#define MAPGENERATOR_PTR_H_

#include <memory>

class MapGenerator;
using MapGeneratorPtr = std::shared_ptr<MapGenerator>;
using MapGeneratorWPtr = std::weak_ptr<MapGenerator>;

#endif // ! ACTORPTR_H_

