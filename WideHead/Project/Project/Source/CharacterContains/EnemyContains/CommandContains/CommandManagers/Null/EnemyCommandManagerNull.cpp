#include "EnemyCommandManagerNull.h"
#include "../../../StateContains/States/EnemyStateName.h"
#include <GSvector2.h>
EnemyStateName EnemyCommandManagerNull::GetCommandState() {
	return EnemyStateName::None;
}

GSvector2 & EnemyCommandManagerNull::GetCommandVector() {
	return GSvector2(0.0f, 0.0f);
}
