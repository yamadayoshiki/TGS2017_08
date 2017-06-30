#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "../Scene/Scene.h"

class World;

//�Q�[����
class GamePlay : public Scene
{
public:
	// �R���X�g���N�^    
	GamePlay(const IGameManagerPtr& gameManager);

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	// �`��     
	virtual void OnDraw()const;
	//�I��
	virtual void End()override;

private:
	//Map�f�[�^�̐ݒ�
	void MapSetDeta();
	//�|�[�Y�̍X�V
	void PauseUpdate();
};

#endif