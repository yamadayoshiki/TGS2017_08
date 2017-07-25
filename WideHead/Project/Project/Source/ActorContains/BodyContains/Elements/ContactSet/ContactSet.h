#ifndef CONTACTSET_H_
#define CONTACTSET_H_
#include "../../../../Utility/Contact/Contact.h"
#include <vector>
namespace Body
{
	//衝突情報集合
	struct ContactSet
	{
		bool m_IsCollide;					//衝突しているか
		std::vector<Contact> m_ContactVec;	//衝突情報配列
		GSvector2 m_SumVec;

		//コンストラクタ
		ContactSet();
		//衝突情報追加
		void Add(Contact contact);
	};
}

#endif // !CONTACTSET_H_