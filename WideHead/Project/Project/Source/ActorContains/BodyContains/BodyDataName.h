#ifndef BODYDATANAME_H_
#define BODYDATANAME_H_
namespace Body {
	//�Փː}�`�f�[�^�\��
	enum class BodyDataName {
		None,		//�Ȃ�
		AABB_32,	//���32�̐����`
		AABB_64,	//���64�̐����`

		PlayerAttackRange,	//�v���C���[�U���͈�
		Player_Open,				//�v���C���[���A�[�����J���Ă���
		Player_Close,				//�v���C���[���A�[������Ă���
		Player_Clip,				//�v���C���[���G������ł���
	};
}
#endif // !BODYDATANAME_H_
