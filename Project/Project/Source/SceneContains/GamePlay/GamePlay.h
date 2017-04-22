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
	//�f�t�H���g�R���X�g���N�^
	GamePlay();
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
	WorldPtr p_World;	//���[���h
};

#endif