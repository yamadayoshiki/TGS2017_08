#ifndef IGAMEMANAGER_H_
#define IGAMEMANAGER_H_

#include "../../Utility/Rederer2D/Renderer2DPtr.h"
#include "../../Utility/InputState/InputStatePtr.h"
#include "../../Utility/EnumRap/EnumRapPtr.h"
#include "../../SceneContains/SceneName.h"
#include"../../CharacterContains/PlayerContains/Player/Player_Parameter.h"

//�Q�[���}�l�[�W���[�C���^�[�t�F�C�X
class IGameManager
{
public:
	//���z�f�X�g���N�^
	virtual ~IGameManager() {}

public:
	//�����_���[�̎擾
	virtual  Renderer2DPtr GetRenderer2D() = 0;
	//�C���v�b�g�X�e�C�g�̎擾
	virtual InputStatePtr GetInputState() = 0;
	//�V�[����Enum�̎擾
	virtual EnumRapPtr<SceneName> GetSceneEnum() = 0;
	//�v���C���[�p�����[�^�[�̎擾
	virtual Player_Parameter GetPlayerParameter() = 0;
	//�v���C���[�p�����[�^�[�̐ݒ�
	virtual void SetPlayerParameter(const Player_Parameter& parameter) = 0;

protected:
	//�I������
	virtual void Finalize() {};

};
#endif // !IGAMEMANAGER_H_
