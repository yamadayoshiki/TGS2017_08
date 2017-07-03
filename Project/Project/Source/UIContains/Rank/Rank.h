#ifndef RANK_H_
#define RANK_H_

#include"../Base/UI_Base.h"
#include<vector>

class Rank :public UI_Base
{
public:
	struct RankDeta
	{
		std::string file_name;
		int StageNumber;
		int RankNumber;
		int Score;
	};
public:
	Rank(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);

	void regist(const std::string & file_name);
	//ランクデータの設定
	void RankSet();

private:
	virtual void onUpdate(float deltaTime)override;
	virtual void onDraw()const override;

	int getIndex(int index, int next);
private:
	using RankDetaList = std::vector<RankDeta>;
	using StageDeta = std::vector<RankDetaList>;
	StageDeta	m_StageDeta;
	int m_Index;
	float m_Timer{ 0.0f };
	int StageIndex;
	int num{ 3 };
	int m_Count{ 0 };
	std::string m_TextureName;
	std::string m_ResultTextureName;
	GSvector2 m_ScorePosition{ 550, 250 };
};
#endif // !RANK_H_
