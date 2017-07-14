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
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);
	// �`��     
	virtual void OnDraw()const;
	//�I��
	virtual void End();

private:
	//�I���̍X�V
	void SelectUpdate();
	//�e�N�X�`���̃p�����[�^
	Texture2DParameterSPtr p_OverParam;
	Texture2DParameterSPtr p_ResultParam;
	Texture2DParameterSPtr p_PauseRTParam;
	Texture2DParameterSPtr p_CursorParam;
	//�e�N�X�`���̊Ǘ��ԍ�
	DrawOrderID m_OrverNum;
	DrawOrderID m_ResultNum;
	DrawOrderID m_PauseRTNum;
	DrawOrderID m_CursorNum;
};

#endif // !GAMEOVER_H_
