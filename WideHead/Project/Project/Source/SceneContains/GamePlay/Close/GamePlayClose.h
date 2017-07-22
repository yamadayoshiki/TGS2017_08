#ifndef GAMEPLAYCLOSE_H_
#define GAMEPLAYCLOSE_H_
#include "../../Scene/ChildScene.h"
#include <map>
class Respawn;
class Texture;
class ZoomSprite;
class GamePlayClose : public ChildScene
{
	enum class State {
		Stop = 0,
		Clear,
		End,
	};
public:
	GamePlayClose();

protected:
	// �J�n     
	virtual void OnStart() override;
	// �X�V     
	virtual void OnUpdate(float deltaTime) override;
	// �`��     
	virtual void OnDraw()const override;
	//�I��
	virtual void OnEnd()override;

protected:
	//�ύX
	void ChangeState(const State next);

private:
	std::map<State, std::shared_ptr<ZoomSprite>> m_SpriteMap;
	State m_CurState;
	std::unique_ptr<Respawn> p_Respown;
	std::unique_ptr<Texture> p_BlackScreen;
};
#endif // !GAMEPLAYCLOSE_H_
