#include "TransitionManager.h"

#include "../Transition/Transition.h"

TransitionManager::TransitionManager() {

}

void TransitionManager::addTransition(const TransitionPtr & transition) {
	m_Transitions.push(transition);
}

void TransitionManager::update(float deltaTime) {
	m_Transitions.top()->update(deltaTime);
}

void TransitionManager::change() {
	m_Transitions.pop();
}
