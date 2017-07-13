#ifndef GAMERESULT_H_
#define GAMERESULT_H_

#include "../Scene/Scene.h"
#include"../SceneManager/SceneManager.h"
#include"../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../StagingContains/TransitionStaging/TransitionPtr.h"

#include <string>
#include<array>

#include<gslib.h>
class World;

//ゲーム中
class GameResult : public Scene
{
public:
	// コンストラクタ    
	GameResult(const IGameManagerPtr& gameManager);

	enum class Rank{
		RankS,
		RankA,
		RankB,
		RankC,
	};
protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
	//描画
	virtual void OnDraw()const;
	//終了
	virtual void End();

private:
	//選択の更新
	void SelectUpdate();

private:
	std::string m_Text;
	std::string m_SelectTextureName;
	std::string m_ResultTextureName;

	TransitionPtr m_Transition;


	typedef std::array<int, 4> RankNolma;
	std::array<RankNolma,8> StageRankNolma;

	SceneManager*	m_SceneManager;

	float timer_{ 0.0f };
	
};

#endif