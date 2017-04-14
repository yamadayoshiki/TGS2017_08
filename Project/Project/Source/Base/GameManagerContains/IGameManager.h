#ifndef IGAMEMANAGER_H_
#define IGAMEMANAGER_H_

#include "../../Utility/Rederer2D/Renderer2D.h"

//�Q�[���}�l�[�W���[�C���^�[�t�F�C�X
class IGameManager
{
public:
	//���z�f�X�g���N�^
	virtual ~IGameManager() 
	{
		Finalize();
	}
	//�R���e���c�̓ǂݍ���
	virtual void LoadContent() = 0;
	//�R���e���c�̍폜
	virtual void UnLoadContent() = 0;

public:
	//�����_���[�̎擾
	virtual Renderer2D* GetRenderer2D() = 0;

protected:
	//�I������
	virtual void Finalize() {};

};
#endif // !IGAMEMANAGER_H_
