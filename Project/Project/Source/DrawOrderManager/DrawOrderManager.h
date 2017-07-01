#ifndef DRAWORDERMANAGER_H_
#define DRAWORDERMANAGER_H_
#include "../Utility/Rederer2D/Renderer2DPtr.h"
#include <iostream>
#include "../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include "DrawOrder.h"
#include <map>
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

//�`��Ǘ�
class DrawOrderManager
{
public:
	//�R���X�g���N�^
	DrawOrderManager(Renderer2DPtr renderer2D);
	//�f�X�g���N�^
	~DrawOrderManager();
	//�v�f�̍폜
	void Clear();
	//�o�^
	DrawOrderID Register(const std::string& texName, const Texture2DParameterPtr& parameter, const DrawOrder order);
	//�폜
	void Remove(const DrawOrderID id);
	//�`��I�u�W�F�N�g�\���̂̎擾
	DrawOrderObject GetDrawObject(const DrawOrderID id);
	//�`��
	void Draw();
private:
	std::map<DrawOrderID,DrawOrderObject> m_DrawOrderSet;	//�`��I�u�W�F�N�g
	int m_Oreder;				//�ǉ���
	Renderer2DPtr p_Renderer;	//�����_���[
};

#endif // !DRAWMANAGER_H_
