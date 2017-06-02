#ifndef PLAYERWATCHPTR_H_
#define PLAYERWATCHPTR_H_
#include <memory>
//ユニークポインタ
class PlayerWatch;
using PlayerWatchUPtr = std::unique_ptr <PlayerWatch>;

#endif