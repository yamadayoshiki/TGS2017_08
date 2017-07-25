#include "ContactSet.h"
#include <GSvector2.h>
namespace Body
{
	ContactSet::ContactSet()
		: m_IsCollide(false)
		, m_SumVec(GSvector2(0.0f, 0.0f)) {
		m_ContactVec.clear();
	}

	void ContactSet::Add(Contact contact) {
		if (m_IsCollide == false) m_IsCollide = true;
		m_ContactVec.push_back(contact);

		if (contact.m_NumContacts == 0) return;
		if (contact.m_Contacts[0].distance < m_SumVec.length())
			return;

		GSvector2 vec = contact.GetExtrusion(0);
		if (isnan(vec.x) || isnan(vec.y)) return;
		m_SumVec = vec;
	}
}