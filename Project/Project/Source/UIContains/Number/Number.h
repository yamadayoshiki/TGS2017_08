#ifndef NUMBER_H_
#define NUMBER_H_
#include "../Base/UI_Base.h"
class NumberTexture;
//UINumbr
class Number : public UI_Base {
public:
	//�R���X�g���N�^
	Number(
		IWorld* world,							//���[���h
		const IGameManagerPtr& gameManager,		//�Q�[���}�l�[�W��
		const DrawOrder drawOrder,				//�`�揇��
		const ITexturePtr& texture,				//�e�N�X�`��
		const std::string& usage);				//�p�r

public:
	void ChangeDisplayMode(const DisplayMode mode) override;

public:
	//�p�r�̎擾
	std::string GetUsage() const;
	//�ԍ��ݒ�
	void SetNum(const int num);


private:
	std::shared_ptr<NumberTexture> p_NumberTexture;		//�����e�N�X�`��
	std::string m_Usage;								//�p�r
};
#endif // !NUMBER_H_
