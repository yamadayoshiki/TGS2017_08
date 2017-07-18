#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include "../Scene/Scene.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include "../../DrawManager/DrawOrderObject.h"
class World;

class GameOver : public Scene
{
public:
	//�R���X�g���N�^
	GameOver(const IGameManagerPtr& gameManager);

protected:
	// �J�n     
	virtual void OnStart() override;
	// �X�V     
	virtual void OnUpdate(float deltaTime) override;
	// �`��     
	virtual void OnDraw()const override;
	//�I��
	virtual void OnEnd() override;
};

#endif // !GAMEOVER_H_
