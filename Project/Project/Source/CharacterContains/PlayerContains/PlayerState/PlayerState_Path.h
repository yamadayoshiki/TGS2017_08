#ifndef PLAYERSTATE_PATH_H_
#define PLAYERSTATE_PATH_H_

//ステートのパス

//通常状態
#include"States\Normal\PlayerState_Close.h"
#include"States\Normal\Move\PlayerState_Idle.h"
#include"States\Normal\Move\PlayerState_Run.h"
#include"States/Normal/Move/PlayerState_Walk.h"
#include"States\Normal\Move\PlayerState_Dash.h"

//アームが開いている状態
#include"States\Open\PlayerState_Open.h"
#include"States\Open\Move\PlayerState_O_Idle.h"
#include"States\Open\Move\PlayerState_O_Walk.h"
#include"States\Open\Move\PlayerState_O_Run.h"

//はさんでいる状態
#include"States\Rounds\PlayerState_Round.h"
#include"States\Rounds\PlayerState_R_Idle.h"
#include"States\Rounds\PlayerState_R_Walk.h"
#include"States\Rounds\PlayterState_R_Run.h"

//潰す状態
#include"States\Crush\PlayerState_Crush.h"
#include"States\Crush\PlayerState_Crush_Barrage.h"
#include"States\Crush\PlayerState_Crush_Hold.h"

//共通
#include"States\Common\PlayerState_Damage.h"
#include"States\Common\PlayerState_Swich.h"
#include"States\Common\PlayerState_Release.h"

#endif // !PLAYERSTATE_PATH_H_
