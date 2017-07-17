#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
class World;
class Number;
class Button;
class Sprite;
//�Q�[����
class GamePlay : public Scene
{
public:
	// �R���X�g���N�^    
	GamePlay(const IGameManagerPtr& gameManager);

protected:
	// �J�n     
	virtual void OnStart() override;
	// �X�V     
	virtual void OnUpdate(float deltaTime) override;
	// �`��     
	virtual void OnDraw()const override;
	//�I��
	virtual void OnEnd()override;

private:
	//Map�f�[�^�̐ݒ�
	void MapSetDeta();
	//�|�[�Y�̍X�V
	void PauseUpdate();

private:
	std::weak_ptr<Number> p_ScoreUI;			//�X�R�A
	std::weak_ptr<Number> p_PlayerRemainingUI;	//�v���C���[�c�@
	std::weak_ptr<Button> p_ButtonUI;			//�|�[�Y��ʃ{�^��UI
	std::weak_ptr<Sprite> p_PauseBack;			//�|�[�Y��ʔw�i
};

#endif