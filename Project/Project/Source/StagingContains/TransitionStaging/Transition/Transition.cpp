#include "Transition.h"

//コンストラクタ
Transition::Transition(const IGameManagerPtr & gameManager) :
	p_GameManager(gameManager), m_IsEnd(false), mMode(Mode::In) {
}

// 仮想デストラクタ     
Transition::~Transition(){
}

// 開始     
void Transition::start(){
	onStart();
}

// 更新     
void Transition::update(float deltaTime){
	onUpdate(deltaTime);
}

// 描画     
void Transition::draw()const {
	onDraw();
}

void Transition::end(){
	onEnd();
}

// モードの切りかえ
void Transition::changeMode(const Mode & mode)
{
	mMode = mode;
}

// 終了フラグ
bool Transition::isEnd(){
	return m_IsEnd;
}

// 開始     
void Transition::onStart(){
}

//更新
void Transition::onUpdate(float deltaTime){
}

//描画
void Transition::onDraw() const{
}
