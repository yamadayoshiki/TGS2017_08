#ifndef PLAYERSTATE_PATH_H_
#define PLAYERSTATE_PATH_H_

//�X�e�[�g�̃p�X

//�ʏ���
#include"States\Normal\PlayerState_Close.h"
#include"States\Normal\Move\PlayerState_Idle.h"
#include"States/Normal/Move/PlayerState_Walk.h"
#include"States\Normal\Move\PlayerState_Dash.h"

//�A�[�����J���Ă�����
#include"States\Open\PlayerState_Open.h"
#include"States\Open\Move\PlayerState_O_Idle.h"
#include"States\Open\Move\PlayerState_O_Walk.h"

//�͂���ł�����
#include"States\Rounds\PlayerState_Round.h"

//�ׂ����
#include"States\Crush\PlayerState_Crush.h"
#include"States\Crush\PlayerState_Crush_Barrage.h"

//����
#include"States\Common\PlayerState_Damage.h"
#include"States\Common\PlayerState_Swich.h"
#include"States\Common\PlayerState_Release.h"
#include"States\Common\PlayerState_Dead.h"

#endif // !PLAYERSTATE_PATH_H_
