#ifndef GAMECREDIT_H_
#define GAMECREDIT_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"

class World;
class Number;
class Button;
class Sprite;
class Rank;
class SceneChildMgr;

//�Q�[���N���A
class GameCredit : public Scene
{
public:
	// �R���X�g���N�^    
	GameCredit(const IGameManagerPtr& gameManager);

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
	//�R���{���̎擾
	std::weak_ptr<Number> GetComboUI();
	//���g���C���̎擾
	std::weak_ptr<Number> GetRetryUI();
	//�����N�̎擾
	std::weak_ptr<Rank> GetRankUI();
	//���U���g���ʂ̊�Չ摜�̎擾
	std::weak_ptr<Sprite> GetPlatform();
	//�u���b�N�摜�̎擾
	std::weak_ptr<Sprite> GetBlock();
	//�g�[�^���X�R�A�t�H���g�摜�̎擾
	std::weak_ptr<Sprite> GetTortal();
	//�}�b�N�X�R���{�t�H���g�摜�̎擾
	std::weak_ptr<Sprite> GetMaxCombo();
	//���g���C���t�H���g�摜�̎擾
	std::weak_ptr<Sprite> GetRetry();

private:
	std::weak_ptr<Number> p_ScoreUI;
	std::weak_ptr<Number> p_ComboUI;
	std::weak_ptr<Number> p_RetryUI;
	std::weak_ptr<Rank> p_RankUI;
	std::weak_ptr<Sprite> p_Platform;
	std::weak_ptr<Sprite> p_Block;
	std::weak_ptr<Sprite> p_Tortal;
	std::weak_ptr<Sprite> p_MaxCombo;
	std::weak_ptr<Sprite> p_Retry;

	std::unique_ptr<SceneChildMgr>
		p_SceneChildMgr;
};

#endif