#include "Rank.h"

#include "../../FileReader/CsvReader.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../Selector/Selector.h"
#include "../../WorldContains/EventMessage/EventMessage.h"
#include "../../SceneContains/SceneName.h"
#include"../../Utility/Score/Score.h"
#include"../../Utility/Animation/Animation.h"
#include"../../TextureContains/AnimationTexture/AnimationTexture.h"
#include <algorithm>

Rank::Rank(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name)
	:UI_Base(world, ActorName::UI_Rank, position, gameManager) {
	regist(file_name);
	RankSet();
}

void Rank::regist(const std::string & file_name)
{
	CsvReader csv = CsvReader(file_name);
	for (int StageNum = 0; StageNum < (csv.rows() -1) / 4 ; StageNum++) {
		RankDetaList list;
		m_StageDeta.push_back(list);
	}

	// 行のループ(0行目は要素の説明なので "row = 1" から)
	for (int row = 1; row < csv.rows(); row++) {
		RankDeta deta;
		// テクスチャのパス&名前
		deta.file_name = csv.get(row, 0);
		deta.StageNumber = csv.geti(row, 1);
		deta.RankNumber = csv.geti(row, 2);
		deta.Score = csv.geti(row, 3);
		m_StageDeta[deta.StageNumber].push_back(deta);
	}
	
	//m_TextureName = "RankBlock";
	//p_Texture = std::make_shared<AnimationTexture>(m_TextureName, p_GameManager->GetRenderer2D(),new Animation(*p_GameManager->GetRenderer2D()->GetTextureRect(m_TextureName), 350, 20));
	//p_Texture->Initialize();
}

void Rank::onUpdate(float deltaTime)
{
	if (m_StageDeta.size() <= 0) return;
	
	//p_Texture->Update(deltaTime);

	
	if (m_Timer >= 20.0f)
	{
		m_TextureName = m_StageDeta[StageIndex].data()[num].file_name;
		if (m_Count > 2) { return; }
		num--;
		m_Timer = 0.0f;
	}
	if (num < 0) {
		num = 3;
		m_Count++;
	}
	m_Timer += deltaTime;
}

void Rank::onDraw() const
{
	if (m_StageDeta.size() <= 0) return;
	p_GameManager->GetRenderer2D()->DrawTexture(m_TextureName, m_ScorePosition);
	//p_Texture->GetParameter()->SetPosition(m_ScorePosition);
	//p_Texture->GetParameter()->SetColor(GScolor(1.0f,1.0f,1.0f,0.5f));
	//p_Texture->Draw();
}

int Rank::getIndex(int index, int next)
{
	return 0;
}

void Rank::RankSet()
{
	if (m_StageDeta.size() <= 0) return;
	StageIndex = p_GameManager->get_MapOrder();
	RankDetaList RankList = m_StageDeta[StageIndex];
	for (int rankDeta = 0; rankDeta < RankList.size(); rankDeta++) {
		if (p_GameManager->GetScore()->ReleaseScore() >= RankList[rankDeta].Score)
		{
			m_ResultTextureName = RankList[rankDeta].file_name;
			break;
		}
	}
}
