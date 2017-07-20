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
#include"../../Utility/Sound/SoundName.h"
#include <algorithm>

Rank::Rank(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name)
	:UI_Base(world, ActorName::UI_Rank, position, gameManager, DrawOrder::UI) {
	regist(file_name);
	m_TextureName = "RankC";
	SE_Number = SE_RANK_C;
	RankSet();
	m_DisplayFlag = false;
}

void Rank::regist(const std::string & file_name)
{
	CsvReader csv = CsvReader(file_name);
	if (csv.rows() == 1) {
		dead();
		return;
	}
	if (file_name == "Resource/StreamingAssets/UI/Credit/UI_Rank.csv") {
		m_Score = p_GameManager->GetScore()->GetTotalScore();
	}
	else{
		m_Score = p_GameManager->GetScore()->ReleaseScore();
	}
	m_Position = GSvector2(csv.getf(1, 4), csv.getf(1, 5));
	m_Usage = csv.get(1, 6);

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
		deta.SE_number = csv.geti(row,7);
		m_StageDeta[deta.StageNumber].push_back(deta);
	}
}

void Rank::onUpdate(float deltaTime)
{
	if (m_StageDeta.size() <= 0) return;
	if (m_DisplayFlag == false) return;
	//補間値の計算
	float t = m_Timer / m_MaxTimer;
	//透明度の補間
	GScolor color = Start_Color.lerp(End_Color, t);
	//スケールの補間
	GSvector2 scale = Start_Scale.lerp(End_Scale, t);
	//パラメータの設定
	p_Texture->GetParameter()->m_Color =color;
	p_Texture->GetParameter()->m_Scale = scale;

	m_Timer = MIN(m_Timer + deltaTime, m_MaxTimer);
}

void Rank::onDraw() const{
}

void Rank::ChangeDisplayMode(const DisplayMode mode){
	p_Texture->ChangeDisplayMode(mode);
	if (mode == DisplayMode::Display) {
		m_DisplayFlag = true;
	}
}

std::string Rank::GetUsage() const
{
	return m_Usage;
}

void Rank::playSE()
{
	gsPlaySE(SE_Number);
}


void Rank::RankSet()
{
	if (m_StageDeta.size() <= 0) return;
	StageIndex = p_GameManager->get_MapOrder();
	RankDetaList RankList = m_StageDeta[StageIndex];
	for (int rankDeta = 3; rankDeta < RankList.size(); rankDeta--) {
		if (m_Score >= RankList[rankDeta].Score)
		{
			m_TextureName = RankList[rankDeta].file_name;
			SE_Number = RankList[rankDeta].SE_number;
		}
	}
	p_Texture = std::make_shared<Texture>(m_TextureName, p_GameManager->GetDrawManager(), DrawOrder::UI);
	//パラメータの設定
	p_Texture->GetParameter()->m_Position = m_Position;
	setPosition(m_Position);
	p_Texture->GetParameter()->m_Center = { 175.0f,175.0f };
}
