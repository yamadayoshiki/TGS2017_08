#ifndef GAMETITLE_H_
#define GAMETITLE_H_

#include "../Scene/Scene.h"
class AnimationFont;
class DropSprite;
class Button;
class SceneChildMgr;
//�^�C�g���V�[��
class GameTitle : public Scene
{
public:
	// �R���X�g���N�^    
	GameTitle(const IGameManagerPtr& gameManager);

protected:
	// �Z�b�g�A�b�v
	virtual void SetUp() override;
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	//�I��
	virtual void OnEnd()override;

public:
	//�^�C�g�����S�̎擾
	std::weak_ptr<DropSprite> GetTitle();
	//B�{�^���������̎擾
	std::weak_ptr<AnimationFont> GetPushBMessage(const int index);
	//�|�[�Y��ʃ{�^��UI�̎擾
	std::weak_ptr<Button> GetButtonUI();

public:
	std::weak_ptr<DropSprite> p_Title;						//�^�C�g�����S
	std::weak_ptr<AnimationFont> p_PushBMessage[13];		//B�{�^��������
	std::weak_ptr<Button> p_Button;							//�{�^��UI

	std::unique_ptr<SceneChildMgr>				//�q�V�[���Ǘ�
		p_SceneChildMgr;
};

#endif