#ifndef CONTACTSET_H_
#define CONTACTSET_H_
#include "../../../../Utility/Contact/Contact.h"
#include <vector>
namespace Body
{
	//�Փˏ��W��
	struct ContactSet
	{
		//�R���X�g���N�^
		ContactSet();
		//�Փˏ��ǉ�
		void Add(Contact contact);

		bool m_IsCollide;					//�Փ˂��Ă��邩
		std::vector<Contact> m_ContactVec;	//�Փˏ��z��
		GSvector2 m_SumVec;
	};
}

#endif // !CONTACTSET_H_