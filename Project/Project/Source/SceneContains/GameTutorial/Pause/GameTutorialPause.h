#ifndef GAMETUTORIALPAUSE_H_
#define GAMETUTORIALPAUSE_H_
#include "../../Scene/ChildScene.h"
//�Q�[����ʃ|�[�Y
class GameTutorialPause : public ChildScene
{
public:
	GameTutorialPause();

protected:
	// �J�n     
	virtual void OnStart() override;
	// �X�V     
	virtual void OnUpdate(float deltaTime) override;
	//�I��
	virtual void OnEnd()override;
};
#endif // !GAMETUTORIALPAUSE_H_
