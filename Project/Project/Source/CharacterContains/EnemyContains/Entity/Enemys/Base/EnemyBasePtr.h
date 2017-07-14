#ifndef ENEMYBASEPTR_H_
#define ENEMYBASEPTR_H_
#include <memory>
class EnemyBase;
using EnemyBasePtr = std::shared_ptr<EnemyBase>;
using EnemyBaseWPtr = std::weak_ptr<EnemyBase>;
#endif
