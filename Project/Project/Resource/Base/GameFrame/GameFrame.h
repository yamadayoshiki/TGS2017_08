#ifndef GAMEFRAME_H_
#define GAMEFRAME_H_

#include<GSgame.h>
#include<memory>

/*��s�錾*/
class World;
class GameManager;

class GameFrame :public gslib::Game
{
public:
	GameFrame();
	~GameFrame();

private:

	// �J�n
	void start() override;
	// �X�V
	void update(float time) override;
	// �`��
	void draw() override;
	// �I��
	void end() override;
	// ���s����
	bool isRunning() override;

private:
	using WorldPtr = std::shared_ptr<World>;
	WorldPtr p_World; // ���[���h�N���X

	GameManager* p_GameManager; //�Q�[���}�l�[�W���[

	bool isEnd_;  // �I���t���O 
};


#endif // !GAMEFRAME_H_