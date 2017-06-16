#ifndef ACTOR_H_
#define ACTOR_H_

#include <gslib.h>
#include <memory>
#include <string>
#include <functional>
#include <forward_list>

#include "../ActorPtr.h"
#include "../ActorName.h"

#include "../../Base/GameManagerContains/IGameManagerPtr.h"
#include "../../TextureContains/ITexturePtr.h"
#include "../../TextureContains/NullTexture/NullTexture.h"

#include "../../Utility/FourDirection/FourDirection.h"
#include "../../Map/MapType.h"

#include "../BodyContains/Interface/IBodyPtr.h"
#include "../BodyContains/NullBody/NullBody.h"
#include "../Transform/TransformPtr.h"

enum class EventMessage;
class IWorld;

//�A�N�^�[�N���X
class Actor
{
public:
	//�R���X�g���N�^
	Actor(
		IWorld* world,
		const ActorName& name,
		const GSvector2& position,
		const IGameManagerPtr& gaemManager,
		const ITexturePtr& texture = std::make_shared<NullTexture>(),
		const IBodyPtr& body = std::make_shared<Body::NullBody>());
	//�R���X�g���N�^
	explicit Actor(const ActorName& name = ActorName::None);
	//���z�f�X�g���N�^
	virtual ~Actor();
	//������
	virtual void initialize();
	//�X�V
	void update(float deltaTime);
	//�`��
	void draw() const;
	//�Փ˔���(�����͎q������A�����͂���P��)
	void collide(Actor& other);
	//���S���Ă��邩
	bool GetDead() const;
	//���S����
	void dead();
	//���O���擾
	const ActorName getName() const;
	//���W���擾
	GSvector2 getPosition() const;

	//�ϊ������擾
	TransformPtr getTransform() const;

	//�q�̌���
	ActorPtr findChildren_NullActor(const ActorName& name);
	//�q�̌����iNullPtr����j
	ActorPtr findChildren(std::function<bool(const Actor&)> fn);
	//�q���m�̏Փ˔���
	void collideChildren(Actor& other);
	//�Z�퓯�m�̏Փ˔���
	void collideSibling();
	//�q�̒ǉ�
	void addChild(const ActorPtr& child);
	//�q������
	void eachChildren(std::function<void(Actor&)> fn);
	//�q������iconst�Łj
	void eachChildren(std::function<void(const Actor&)> fn) const;
	//�q���폜����
	void removeChildren(std::function <bool(Actor& actor)> fn);
	//�q���폜����
	void removeChildren();
	//�q������
	void clearChildren();
	//���b�Z�[�W����
	void handleMessage(EventMessage message, void* param);

	//���[���h��ݒ�
	void SetWorld(IWorld* world);
	//���[���h���擾
	IWorld* getWorld() const;
	//����̌`�̎擾
	IBodyPtr getBody() const;

	int getCount() const;

	virtual MapType GetMapType() const;

	//���W�̐ݒ�
	void setPosition(const GSvector2& pos);
	//�p�x�̐ݒ�
	void setAngle(const float& angle);

	//�e�N�X�`�����擾
	ITexturePtr getTexture() const;
	//csv�Ő���(�g�p���p�����override)
	virtual ActorPtr CsvGenerate(const int x, const int y, const int csvparam);

	// �R�s�[�֎~
	Actor(const Actor& other) = delete;
	Actor& operator = (const Actor& other) = delete;

protected:
	//���b�Z�[�W����
	virtual void onMessage(EventMessage message, void* param) {}
	//�X�V
	virtual void onUpdate(float deltaTime) {}
	//�`��
	virtual void onDraw() const {}
	//�Փ˃��A�N�V����
	virtual void onCollide(Actor& other) {}
public:
	//�Փ˔���
	bool isCollide(const Actor& other);


protected:
	IWorld* p_World;				//���[���h
	IGameManagerPtr p_GameManager;	//�Q�[���}�l�[�W��
	ActorName m_Name;				//���O
	TransformPtr p_Transform;		//�g�����X�t�H�[��
	ITexturePtr	p_Texture;			//�e�N�X�`��
	IBodyPtr p_Body;				//�Փ˔���}�`
	bool m_dead;					//���S���Ă��邩

private:
	std::forward_list<ActorPtr> m_children;	//�q�A�N�^�[
};

#endif