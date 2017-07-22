#include "Composite.h"

Composite::Composite() {
	m_Children.clear();
}

Composite::~Composite() {
}

void Composite::AddChild(ComponentSPtr child) {
	m_Children.push_front(child);
}

void Composite::RemoveChild(ComponentSPtr child) {
	if (m_Children.empty() == true)return;
	for (auto itr = m_Children.begin(); itr != m_Children.end(); itr++)
		if (*itr == child) {
			m_Children.erase_after(itr);
			return;
		}
}

int Composite::ChildrenCount() {
	if (m_Children.empty() == true) return 0;
	return std::distance(m_Children.begin(), m_Children.end());
}
