#ifndef CHARGE_H_
#define CHARGE_H_


#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"

#include<string>

class Renderer2D;

//�`���[�W�G�t�F�N�g�N���X
class Charge :public Actor
{
public:
	//�R���X�g���N�^
	Charge(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager);
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
	//�����_���[
	Renderer2DPtr			p_Renderer;
	AnimationTexture*		p_AnimationTexture;
	Animation*				p_Animation;
	std::string				m_Name;
};
#endif // !CHARGE_H_
