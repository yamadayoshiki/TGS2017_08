#ifndef IENEMYCOMMANDMANAGERPTR_H_
#define IENEMYCOMMANDMANAGERPTR_H_

#include <memory>

class IEnemyCommandManager;
using IEnemyCommandManagerUPtr = std::unique_ptr<IEnemyCommandManager>;

#endif
