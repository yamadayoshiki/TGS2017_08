#ifndef GAMERESULT_H_
#define GAMERESULT_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"

class World;
class Number;
class Button;
class Sprite;
class Rank;
class SceneChildMgr;

//�Q�[�����U���g
class GameResult : public Scene
{
public:
	// �R���X�g���N�^    
	GameResult(const IGameManagerPtr& gameManager);

protected:
	// �Z�b�g�A�b�v
	void SetUp() override;
	// �J�n     
	virtual void OnStart() override;
	// �X�V     
	virtual void OnUpdate(float deltaTime) override;
	//�`��
	virtual void OnDraw()const override;
	//�I��
	virtual void OnEnd() override;
	// ���b�Z�[�W����
	virtual void HandleMessage(EventMessage message, void* param)override;

public:
	//�X�R�A�̎擾
	std::weak_ptr<Number> GetScoreUI();
	//�����N�̎擾
	std::weak_ptr<Rank> GetRankUI();
	//���U���g���ʂ̊�Չ摜�̎擾
	std::weak_ptr<Sprite> GetPlatform();
	//�u���b�N�摜�̎擾
	std::weak_ptr<Sprite> GetBlock();
	//�u���b�N2�摜�̎擾
	std::weak_ptr<Sprite> GetBlock2();

private:
	std::weak_ptr<Number> p_ScoreUI;
	std::weak_ptr<Rank> p_RankUI;
	std::weak_ptr<Sprite> p_Platform;
	std::weak_ptr<Sprite> p_Block;
	std::weak_ptr<Sprite> p_Block2;

	std::unique_ptr<SceneChildMgr>
		p_SceneChildMgr;
};

#endif