#ifndef IWORLD_PTR_H_
#define IWORLD_PTR_H_

#include<memory>

class IWorld;
using IWorldPtr = std::shared_ptr<IWorld>;

#endif // ! IWORLD_PTR_H_