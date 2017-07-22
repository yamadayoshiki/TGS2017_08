#ifndef CONTACT_H_
#define CONTACT_H_
#include "ContactPoint.h"
#include <vector>
namespace Body
{
	//Õ“Ëî•ñ
	struct Contact
	{
		Contact();
		void Add(const ContactPoint point);
		GSvector2 GetExtrusion(int i);
		int m_NumContacts;	//Õ“Ë‚Ì”
		std::vector<ContactPoint> m_Contacts;	//Õ“Ë“_”z—ñ
	};

	inline Contact::Contact()
		: m_NumContacts(0) {
		m_Contacts.clear();
	}

	inline void Contact::Add(const ContactPoint point) {
		m_NumContacts++;
		m_Contacts.push_back(point);
	}

	inline GSvector2 Contact::GetExtrusion(int i) {
		if (i >= m_NumContacts) return GSvector2(0.0f, 0.0f);
		return m_Contacts[i].normal * m_Contacts[i].distance;
	}
}
#endif // !CONTACT_H_
