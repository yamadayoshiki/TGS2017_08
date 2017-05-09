#ifndef GAMECREDIT_H_
#define GAMECREDIT_H_

#include "../Scene/Scene.h"

class World;

//�Q�[����
class GameCredit : public Scene
{
public:
	// �R���X�g���N�^    
	GameCredit(const IGameManagerPtr& gameManager);
	// ���̃V�[����Ԃ�
	virtual SceneName Next() const override;
	// �I��
	virtual void End() override;

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
};

#endif