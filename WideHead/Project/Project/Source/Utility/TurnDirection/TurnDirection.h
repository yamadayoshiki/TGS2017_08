#ifndef TURNDIRECTION_H_
#define TURNDIRECTION_H_

//回転方向名前
enum class TurnDirectionName
{
	Clockwise,		//時計回り
	AntiClockwise,	//反時計回り

	None,			//なし
};

//回転方向
struct TurnDirection
{
	struct
	{
		TurnDirectionName name;
	};

	//コンストラクタ
	TurnDirection(TurnDirectionName name);
	//デフォルトコンストラクタ
	TurnDirection();
	//反転
	TurnDirection Reversal();
	//反転
	TurnDirection GetReversal();
};

#endif