#ifndef GAMETUTORIALREADY_H_
#define GAMETUTORIALREADY_H_
#include "../../Scene/ChildScene.h"
#include <map>
class ZoomSprite;
//�Q�[���v���C����
class GameTutorialReady : public ChildScene{
	enum class State {
		Title = 0,
		Start,
		End,
	};
public:
	GameTutorialReady();

protected:
	// �J�n     
	virtual void OnStart() override;
	// �X�V     
	virtual void OnUpdate(float deltaTime) override;
	//�I��
	virtual void OnEnd()override;

protected:
	//�ύX
	void ChangeState(const State next);

private:
	std::map<State, std::shared_ptr<ZoomSprite>>
		m_SpriteMap;
	State m_CurState;
};
#endif // !GAMEPLAYREADY_H_