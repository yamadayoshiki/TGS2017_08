#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "../Scene/Scene.h"
#include <memory>

class World;
class GameManager;

//�Q�[����
class GamePlay : public Scene
{
public:
	// �R���X�g���N�^    
	GamePlay(GameManager* GameManager);
	// �`��     
	virtual void Draw() const override;
	// ���̃V�[����Ԃ�     
	virtual SceneName Next() const override;
	// �I��     
	virtual void End() override;

protected:
	// �J�n     
	virtual void OnStart();
	// �X�V     
	virtual void OnUpdate(float deltaTime);

private:
	using WorldPtr = std::shared_ptr<World>;
	WorldPtr p_World;

	
	GameManager*		p_GameManager;
};

#endif