#ifndef IWORLDPTR_H_
#define IWORLDPTR_H_

#include<memory>

class IWorld;
using IWorldPtr = std::shared_ptr<IWorld>;
using IWorldWPtr = std::weak_ptr<IWorld>;

#endif // ! IWORLDPTR_H_