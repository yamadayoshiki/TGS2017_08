#ifndef PLAYERSTATE_PATH_H_
#define PLAYERSTATE_PATH_H_

//�X�e�[�g�̃p�X

//�ʏ���
#include"States\Normal\PlayerState_Close.h"
#include"States\Normal\Move\PlayerState_Idol.h"
#include"States\Normal\Move\PlayerState_Run.h"
#include"States/Normal/Move/PlayerState_Walk.h"

//�A�[�����J���Ă�����
#include"States\Open\PlayerState_Open.h"
#include"States\Open\Move\PlayerState_O_Idol.h"
#include"States\Open\Move\PlayerState_O_Walk.h"
#include"States\Open\Move\PlayerState_O_Run.h"

//�͂���ł�����
#include"States\Rounds\PlayerState_R_Idol.h"
#include"States\Rounds\PlayerState_R_Walk.h"
#include"States\Rounds\PlayterState_R_Run.h"

//�ׂ����
#include"States\Crush\PlayerState_Crush.h"
#include"States\Crush\PlayerState_Crush_Barrage.h"
#include"States\Crush\PlayerState_Crush_Hold.h"

//����
#include"States\Common\PlayerState_Damage.h"
#include"States\Common\PlayerState_Swich.h"

#endif // !PLAYERSTATE_PATH_H_
