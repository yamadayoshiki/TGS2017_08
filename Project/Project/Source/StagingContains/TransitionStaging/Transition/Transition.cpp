#include "Transition.h"

//�R���X�g���N�^
Transition::Transition(const IGameManagerPtr & gameManager) :
	p_GameManager(gameManager), m_IsEnd(false), mMode(Mode::In) {
}

// ���z�f�X�g���N�^     
Transition::~Transition(){
}

// �J�n     
void Transition::start(){
	onStart();
}

// �X�V     
void Transition::update(float deltaTime){
	onUpdate(deltaTime);
}

// �`��     
void Transition::draw()const {
	onDraw();
}

void Transition::end(){
	onEnd();
}

// ���[�h�̐؂肩��
void Transition::changeMode(const Mode & mode)
{
	mMode = mode;
}

// �I���t���O
bool Transition::isEnd(){
	return m_IsEnd;
}

// �J�n     
void Transition::onStart(){
}

//�X�V
void Transition::onUpdate(float deltaTime){
}

//�`��
void Transition::onDraw() const{
}
