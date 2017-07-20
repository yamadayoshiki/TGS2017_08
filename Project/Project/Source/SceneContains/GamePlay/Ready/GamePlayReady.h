#ifndef GAMEPLAYREADY_H_
#define GAMEPLAYREADY_H_
#include "../../Scene/ChildScene.h"
#include <vector>
class AnimationSpriteBase;
//�Q�[���v���C����
class GamePlayReady : public ChildScene {
public:
	GamePlayReady();

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
	void ChangeSprite();

private:
	std::vector<std::shared_ptr<AnimationSpriteBase>> m_SpriteVector;
	int m_CurIndex;
};
#endif // !GAMEPLAYREADY_H_