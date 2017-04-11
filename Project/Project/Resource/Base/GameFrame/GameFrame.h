#ifndef GAMEFRAME_H_
#define GAMEFRAME_H_

#include<GSgame.h>
#include<memory>

/*先行宣言*/
class World;
class GameManager;

class GameFrame :public gslib::Game
{
public:
	GameFrame();
	~GameFrame();

private:

	// 開始
	void start() override;
	// 更新
	void update(float time) override;
	// 描画
	void draw() override;
	// 終了
	void end() override;
	// 実行中か
	bool isRunning() override;

private:
	using WorldPtr = std::shared_ptr<World>;
	WorldPtr p_World; // ワールドクラス

	GameManager* p_GameManager; //ゲームマネージャー

	bool isEnd_;  // 終了フラグ 
};


#endif // !GAMEFRAME_H_