#ifndef SCENENAME_H_
#define SCENENAME_H_

enum class SceneName
{
	GameTitle = 0,		//タイトル
	GameTutorial,
	GameSelect,
	GamePlay,			//ゲーム中
	GameResult,
	GameCredit,
	GameEnd,
	GameOver,

	//Title
	Select,

	//Result
	ResultStart,
	ResultStaging,
	ResultEnd,

	//Credit
	CreditStart,
	CreditStaging,
	CreditEnd,

	//Play
	Start,
	Play,
	Pause,
	Close,

	NaganoScene,
	NakayamaScene,
	YamadaScene,
	None,
};

#endif // !SCENENAME_H_
