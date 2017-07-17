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
#include"../../Utility/Sound/SoundName.h"
#include"../../Utility/Texture2DParameter/Texture2DParameter.h"
#include <algorithm>

Rank::Rank(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name)
	:UI_Base(world, ActorName::UI_Rank, position, gameManager, DrawOrder::UI) {
	regist(file_name);
	m_TextureName = "RankC";
	RankSet();
}

void Rank::regist(const std::string & file_name)
{
	CsvReader csv = CsvReader(file_name);
	if (csv.rows() == 1) {
		dead();
		return;
	}

	m_ScorePosition = GSvector2(csv.getf(1, 4), csv.getf(1, 5));

	for (int StageNum = 0; StageNum < (csv.rows() - 1) / 4; StageNum++) {
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
}

void Rank::onUpdate(float deltaTime)
{
	if (m_StageDeta.size() <= 0) return;
	//gsPlaySE(SE_SCORE_ROLE);

	//補間値の計算
	float t = m_Timer / m_MaxTimer;
	//透明度の補間
	GScolor color = Start_Color.lerp(End_Color, t);
	//スケールの補間
	GSvector2 scale = Start_Scale.lerp(End_Scale, t);
	//パラメータの設定
	p_Texture->GetParameter()->m_Color = { 1.0f,1.0f,1.0f,color.a };
	p_Texture->GetParameter()->m_Scale = scale;

	m_Timer = MIN(m_Timer + deltaTime, m_MaxTimer);
}

void Rank::onDraw() const
{
}

void Rank::ChangeDisplayMode(const DisplayMode mode){
	p_Texture->ChangeDisplayMode(mode);
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
	for (int rankDeta = 3; rankDeta < RankList.size(); rankDeta--) {
		if (p_GameManager->GetScore()->ReleaseScore() >= RankList[rankDeta].Score)
		{
			m_TextureName = RankList[rankDeta].file_name;
		}
	}
	p_Texture = std::make_shared<Texture>(m_TextureName, p_GameManager->GetDrawManager(), DrawOrder::UI_Front1);
	//パラメータの設定
	p_Texture->GetParameter()->m_Position = m_ScorePosition;
	p_Texture->GetParameter()->m_Center = { 175.0f,175.0f };
}
