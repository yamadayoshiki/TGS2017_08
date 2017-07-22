#ifndef DRAWMANAGER_H_
#define DRAWMANAGER_H_
#include "../Utility/Rederer2D/Renderer2DPtr.h"
#include "../Utility/Texture2DParameter/Factory/Texture2DParamFactoryPtr.h"
#include "DrawOrder.h"
#include <map>
#include "DrawOrderObject.h"
#include "DisplayMode.h"

struct GSrect;
//�`��Ǘ�
class DrawManager
{
public:
	//�R���X�g���N�^
	DrawManager(Renderer2DPtr renderer2D);
	//�f�X�g���N�^
	~DrawManager();
	//�v�f�̍폜
	void Clear();
	//�o�^(�p�����[�^�f�t�H���g�ݒ�)
	DrawOrderID RegisterDefaultParam(const std::string& texName, Texture2DParameterSPtr& param, const DrawOrder order);
	//�o�^
	DrawOrderID Register(const std::string& texName, const Texture2DParameterSPtr& parameter, const DrawOrder order);
	//�\�����[�h�ύX
	void ChageDisplayMode(const DrawOrderID id, const DisplayMode mode);
	//�폜
	void Remove(const DrawOrderID id);
	//�`��I�u�W�F�N�g�\���̂̎擾
	DrawOrderObject GetDrawObject(const DrawOrderID id);
	//�`��
	void Draw();
	//�`��e�N�X�`����`�̎擾
	GSrect GetRect(const std::string& texName);
	//�`�揇���ύX
	void ChangeOrder(const DrawOrderID id, const DrawOrder drawOrder);

private:
	std::map<DrawOrderID, DrawOrderObject>
		m_DrawOrderMap;				//�`��I�u�W�F�N�g
	std::map<DrawOrderID, DrawOrderObject>
		m_NonDisplayDrawOrderMap;	//��\���`��I�u�W�F�N�g
	int m_Oreder;					//�ǉ���
	Renderer2DPtr p_Renderer;		//�����_���[
	Texture2DParamFactoryUPtr
		p_Texture2DParamFactory;	//�e�N�X�`���p�����[�^�H��

};

#endif // !DRAWMANAGER_H_
