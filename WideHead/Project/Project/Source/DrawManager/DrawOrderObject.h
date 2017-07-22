#ifndef DRAWORDEROBJECT_H_
#define DRAWORDEROBJECT_H_
#include "../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include <iostream>
using DrawOrderID = int;
//�`��I�u�W�F�N�g�\����
struct DrawOrderObject
{
	DrawOrderID id;					//�`�揇
	std::string texName;			//�e�N�X�`���̖��O
	Texture2DParameterWPtr param;	//�e�N�X�`���̃p�����[�^

									//std::set�p��r���Z�q
	bool operator < (const DrawOrderObject& other) {
		return this->id < other.id;
	}
};
#endif // !DRAWORDEROBJECT_H_
