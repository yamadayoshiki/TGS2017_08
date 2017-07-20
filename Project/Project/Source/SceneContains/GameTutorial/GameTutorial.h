#ifndef GAMETUTORIAL_H_
#define GAMETUTORIAL_H_
#include "../Scene/Scene.h"
class Button;
class Sprite;
class SceneChildMgr;
class Guide;
class BreakWall;
class Enemy05;
class Enemy12;
class GameTutorial : public Scene
{
public:
	GameTutorial(const IGameManagerPtr& gameManager);

protected:
	// �Z�b�g�A�b�v
	virtual void SetUp() override;
	// �J�n
	virtual void OnStart() override;
	// �X�V
	virtual void OnUpdate(float deltaTime) override;
	//�I��
	virtual void OnEnd()override;
	// ���b�Z�[�W����
	virtual void HandleMessage(EventMessage message, void* param)override;
public:
	//�|�[�Y��ʃ{�^��UI�̎擾
	std::weak_ptr<Button> GetButtonUI();
	//�|�[�Y��ʔw�i�̎擾
	std::weak_ptr<Sprite> GetPauseBack();
	//�K�C�h�̎擾
	std::shared_ptr<Guide> GetGuide();
	//�EBreakWall�̎擾
	std::shared_ptr<BreakWall> GetBreakWall();
	//Enemy05�̎擾
	std::shared_ptr<Enemy05> GetEnemy05();
	//Enemy12�̎擾
	std::shared_ptr<Enemy12> GetEnemy12();
protected:
	//Map�f�[�^�̐ݒ�
	virtual void MapSetDeta();
protected:
	std::unique_ptr<SceneChildMgr>				//�q�V�[���Ǘ�
		p_SceneChildMgr;

private:
	std::weak_ptr<Button> p_ButtonUI;			//�|�[�Y��ʃ{�^��UI
	std::weak_ptr<Sprite> p_PauseBack;			//�|�[�Y��ʔw�i
	std::shared_ptr<Guide> p_Guide;
	std::shared_ptr<BreakWall> p_BreakWall;
	std::shared_ptr<Enemy05> p_Enemy05;
	std::shared_ptr<Enemy12> p_Enemy12;
};

#endif // !GAAMETUTORIAL_H_
