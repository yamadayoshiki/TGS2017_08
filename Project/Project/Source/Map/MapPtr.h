#ifndef MAPPTR_H_
#define MAPPTR_H_
#include <memory>
class Map;
using MapPtr = std::shared_ptr<Map>;
using MapWPtr = std::weak_ptr<Map>;

#endif // !MAPPTR_H_