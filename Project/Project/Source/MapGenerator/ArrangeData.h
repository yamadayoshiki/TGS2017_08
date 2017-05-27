#ifndef ARRANGEDATA_H_
#define ARRANGEDATA_H_

#include "../Utility/FourDirection/FourDirection.h"

//配置データ
struct ArrangeData
{
	struct
	{
		int actorKey;			//配置するアクターのキー
		FourDirection front;	//配置するアクターの向き
	};

	//デフォルトコンストラクタ
	ArrangeData() {}

	void SetData(const int index)
	{
		//下1桁を向きデータに変換
		front = FourDirection(index % 10);
		//それ以外をキーに変換
		actorKey = index / 10;
	}
};

#endif // !Arrange
