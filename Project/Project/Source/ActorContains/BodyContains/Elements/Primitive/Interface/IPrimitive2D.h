#ifndef IPRIMITIVE2D_H_
#define IPRIMITIVE2D_H_
#include "..\PrimitiveName.h"
struct GSvector2;
namespace Body
{
	struct Contact;
	//�QD�v���~�e�B�u�C���^�[�t�F�C�X
	struct IPrimitive2D
	{
		//���O�̎擾
		virtual PrimitiveName GetName() const = 0;
		//���W�A��]�̐ݒ�
		virtual void SetParam(const GSvector2& position, const float angle, const GSvector2& offsetVec) = 0;
		//�Փ˂��Ă��邩
		virtual Contact IsCollide(IPrimitive2D& p) = 0;
		//�N���[������
		virtual IPrimitive2D* Clone() = 0;
	};
}
#endif // !IPRIMITIVE2D_H_
