#ifndef PLAYERSTATE_PATH_H_
#define PLAYERSTATE_PATH_H_

//ステートのパス

//通常状態
#include"States\Normal\Move\PlayerState_Idol.h"
#include"States\Normal\Move\PlayerState_Run.h"
#include"States/Normal/Move/PlayerState_Walk.h"

//アームが開いている状態
#include"States\Open\PlayerState_Open.h"
#include"States\Open\Move\PlayerState_O_Idol.h"
#include"States\Open\Move\PlayerState_O_Walk.h"
#include"States\Open\Move\PlayerState_O_Run.h"

//共通
#include"States\Normal\PlayerState_Damage.h"

#endif // !PLAYERSTATE_PATH_H_
