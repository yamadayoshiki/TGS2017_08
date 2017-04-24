#ifndef ENEMY_ICOMMAND_H_
#define ENEMY_ICOMMAND_H_

enum class EnemyStateName;
struct GSvector2;

//�G�l�~�[�ɑ΂���R�}���h�C���^�[�t�F�C�X
class Enemy_ICommand
{
public:
	//���z�f�X�g���N�^
	virtual ~Enemy_ICommand() {}
	//������
	virtual void Initialize() = 0;
	//�X�V
	virtual void Update() = 0;
	//�I��
	virtual void Finalize() = 0;
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() = 0;
	//�I�����Ă��邩
	virtual bool IsEnd() = 0;
	//�ړ��x�N�g���̎擾
	virtual GSvector2& GetVelocity() = 0;
	//�X�e�[�g�I���t���O�̐ݒ�
	virtual void SetStateEnd(bool stateEnd) = 0;
};

#endif // !ENEMY_ICOMMAND_H_
