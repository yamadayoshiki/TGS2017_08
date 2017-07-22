#ifndef ENEMYSTATEMANAGERPTR_H_
#define ENEMYSTATEMANAGERPTR_H_
#include <memory>
class EnemyStateManager;
using EnemyStateManagerPtr = std::shared_ptr<EnemyStateManager>;
using EnemyStateManagerUPtr = std::unique_ptr<EnemyStateManager>;
#endif // !ENEMYSTATEMANAGERPTR_H_
