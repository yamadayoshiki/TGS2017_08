#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
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
	virtual void OnEnd()override;

private:
	//Map�f�[�^�̐ݒ�
	void MapSetDeta();
	//�|�[�Y�̍X�V
	void PauseUpdate();

private:
	Texture2DParameterSPtr p_Back;
	int m_Back;
};

#endif