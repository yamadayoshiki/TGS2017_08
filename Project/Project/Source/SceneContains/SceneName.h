#ifndef SCENENAME_H_
#define SCENENAME_H_

enum class SceneName
{
	GameTitle = 0,		//�^�C�g��
	GameTutorial,
	GameSelect,
	GamePlay,			//�Q�[����
	GameResult,
	GameCredit,
	GameEnd,
	GameOver,

	//Result
	ResultStart,
	ResultStaging,
	ResultEnd,

	//Credit
	CreditStart,
	CreditStaging,
	CreditEnd,

	NaganoScene,
	NakayamaScene,
	YamadaScene,
	None,
};

#endif // !SCENENAME_H_
