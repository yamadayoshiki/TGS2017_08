#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
class World;
class Number;
class Button;
class Sprite;
class SceneChildMgr;
//�Q�[����
class GamePlay : public Scene
{
public:
	// �R���X�g���N�^    
	explicit GamePlay(const IGameManagerPtr& gameManager);

protected:
	// �Z�b�g�A�b�v
	virtual void SetUp() override;
	// �J�n
	virtual void OnStart() override;
	// �X�V
	virtual void OnUpdate(float deltaTime) override;
	// �`��     
	virtual void OnDraw()const override;
	//�I��
	virtual void OnEnd()override;
	// ���b�Z�[�W����
	virtual void HandleMessage(EventMessage message, void* param)override;

public:
	//�X�R�A�̎擾
	std::weak_ptr<Number> GetScoreUI();
	//�v���C���[�c�@�̎擾
	std::weak_ptr<Number> GetPlayerRemainingUI();
	//�|�[�Y��ʃ{�^��UI�̎擾
	std::weak_ptr<Button> GetButtonUI();
	//�|�[�Y��ʔw�i�̎擾
	std::weak_ptr<Sprite> GetPauseBack();

protected:
	//Map�f�[�^�̐ݒ�
	virtual void MapSetDeta();

protected:
	std::weak_ptr<Number> p_ScoreUI;			//�X�R�A
	std::weak_ptr<Number> p_PlayerRemainingUI;	//�v���C���[�c�@
	std::weak_ptr<Button> p_ButtonUI;			//�|�[�Y��ʃ{�^��UI
	std::weak_ptr<Sprite> p_PauseBack;			//�|�[�Y��ʔw�i

	std::unique_ptr<SceneChildMgr>				//�q�V�[���Ǘ�
		p_SceneChildMgr;
};

#endif