#ifndef RESULT_START_H_
#define RESULT_START_H_

#include"../Scene/Scene.h"

class ResultStart :public Scene
{
public:
	//�R���X�g���N�^
	ResultStart(const IGameManagerPtr& gameManager);

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	//�`��
	virtual void OnDraw()const;
	//�I��
	virtual void End();
};
#endif // !RESULT_START_H_
