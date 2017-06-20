#ifndef CHARGE_H_
#define CHARGE_H_


#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"
#include"../../../CharacterContains/PlayerContains/Player/PlayerPtr.h"

#include<string>

class Renderer2D;

//�`���[�W�G�t�F�N�g�N���X
class Charge :public Actor
{
private:
	enum Charge_Stage
	{
		Zero,	//0�Ԗ�
		Frist,	//1�i�K��
		Second,	//2�i�K��
		Third,	//3�i�K��
	};
public:
	//�R���X�g���N�^
	Charge(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager,const Player_WPtr& player);
	//�f�X�g���N�^
	~Charge();
	//������
	virtual void initialize()override;
	//�X�V����
	virtual void onUpdate(float deltaTime)override;
	//�`�揈��
	virtual void onDraw()const override;
	//�Փ˔���
	virtual void onCollide(Actor& other)override{}

private:
	//�`���[�W�i�K�̍X�V
	void ChargeUpdate();

private:
	//�����_���[
	Renderer2DPtr			p_Renderer;
	Player_WPtr				p_Player;
	AnimationTexture*		p_AnimationTexture;
	Animation*				p_Animation;
	std::string				m_CurrrentName;
	std::string				m_PreviosName;
	Charge_Stage			m_Charge_Stage;
};
#endif // !CHARGE_H_
