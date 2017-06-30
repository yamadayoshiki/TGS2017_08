#ifndef GAMERESULT_H_
#define GAMERESULT_H_

#include "../Scene/Scene.h"
#include <string>
#include<array>

#include<gslib.h>
class World;

//�Q�[����
class GameResult : public Scene
{
public:
	// �R���X�g���N�^    
	GameResult(const IGameManagerPtr& gameManager);

	enum class Rank{
		RankS,
		RankA,
		RankB,
		RankC,
	};
protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	//�`��
	virtual void OnDraw()const;
	//�I��
	virtual void End();

private:
	//�I���̍X�V
	void SelectUpdate();

private:
	std::string m_Text;
	std::string m_SelectTextureName;
	std::string m_ResultTextureName;
	//���W
	GSvector2 m_ScorePosition;

	typedef std::array<int, 4> RankNolma;
	std::array<RankNolma,8> StageRankNolma;

};

#endif