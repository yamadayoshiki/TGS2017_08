#ifndef PLAYERPTR_H_
#define PLAYERPTR_H_
#include <memory>

class Player;
using PlayerPtr = std::shared_ptr<Player>;

using Player_WPtr = std::weak_ptr<Player>;

#endif