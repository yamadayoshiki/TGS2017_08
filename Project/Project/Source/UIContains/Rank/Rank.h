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
	//用途の取得
	std::string GetUsage() const;

private:
	using RankDetaList = std::vector<RankDeta>;
	using StageDeta = std::vector<RankDetaList>;
	StageDeta	m_StageDeta;
	float m_MaxTimer{ 60.0f };
	float m_Timer{ 0.0f };
	int StageIndex;
	std::string m_TextureName;
	GSvector2 m_Position;
	GScolor Start_Color{ 0.0f,0.0f,0.0f,0.0f };
	GScolor End_Color{1.0f,1.0f,1.0f,1.0f};
	GSvector2 Start_Scale{ 3.0f,3.0f };
	GSvector2 End_Scale{ 1.0f,1.0f };
	std::string m_Usage;
	bool m_DisplayFlag;
};
#endif // !RANK_H_
