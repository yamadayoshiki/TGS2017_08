#ifndef RANK_H_
#define RANK_H_

#include"../Base/UI_Base.h"
#include"../../TextureContains/Texture/Texture.h"
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

public:
	void ChangeDisplayMode(const DisplayMode mode) override;

private:
	int getIndex(int index, int next);
private:
	using RankDetaList = std::vector<RankDeta>;
	using StageDeta = std::vector<RankDetaList>;
	StageDeta	m_StageDeta;
	int m_Index;
	float m_MaxTimer{ 60.0f };
	float m_Timer{ 0.0f };
	int StageIndex;
	int num{ 3 };
	int m_Count{ 0 };
	std::string m_TextureName;
	GSvector2 m_ScorePosition{ 880, 500 };
	GScolor Start_Color{ 0.0f,0.0f,0.0f,0.0f };
	GScolor End_Color{1.0f,1.0f,1.0f,1.0f};
	GSvector2 Start_Scale{ 3.0f,3.0f };
	GSvector2 End_Scale{ 1.0f,1.0f };
};
#endif // !RANK_H_
