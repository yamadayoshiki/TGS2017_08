#include "EnemyCommandNull.h"
#include <GSvector2.h>
#include "../EnemyCommandName.h"
#include "../../../StateContains/States/EnemyStateName.h"
EnemyCommandName EnemyCommandNull::GetNextCommand() const {
	return EnemyCommandName::None;
}

EnemyStateName EnemyCommandNull::GetCurrentStateName() const {
	return EnemyStateName::None;
}

GSvector2 EnemyCommandNull::GetVelocity() const {
	return GSvector2(0.0f, 0.0f);
}