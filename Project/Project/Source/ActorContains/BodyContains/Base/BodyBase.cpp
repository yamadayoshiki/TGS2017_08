#include "BodyBase.h"
#include "../BodyName.h"
#include <cassert>

//�R���X�g���N�^
Body::BodyBase::BodyBase(const BodyName name)
	: m_Name(name)
	, m_IsExist(true) {
}

//�f�X�g���N�^
Body::BodyBase::~BodyBase() {
}

//�Փ˂��Ă��邩
bool Body::BodyBase::IsCollide(IBody* other) {
	if (m_IsExist == false || other->IsExist() == false)
		return false;

	switch (other->GetName())
	{
	case BodyName::None:
		return false;

	case BodyName::AARectangle:
		return IsCollide((AARectangle*)other);

	case BodyName::Rectangle:
		return IsCollide((Rectangle*)other);

	case BodyName::Line:
		return IsCollide((Line*)other);

	default:
		assert(!"Can't Collide");
		return false;
		break;
	}
}

//���O�̎擾
BodyName Body::BodyBase::GetName() const {
	return m_Name;
}

//�Փˉ\���̎擾
bool Body::BodyBase::IsExist() const {
	return m_IsExist;
}		

//�g�����X�t�H�[���̐ݒ�
void Body::BodyBase::SetTransform(const TransformPtr & transform){
	p_Transform = transform;
}

//�Փˉ\���̐ݒ�
void Body::BodyBase::SetExist(bool isExist) {
	m_IsExist = isExist;
}

//�g�����X�t�H�[���̎擾
TransformPtr Body::BodyBase::GetTransform() const {
	return p_Transform;
}
