#include "ChildScene.h"
#include "../../WorldContains/EventMessage/EventMessage.h"

ChildScene::ChildScene()
	:Scene() {
}

ChildScene::~ChildScene() {
}

void ChildScene::Start() {
	m_IsEnd = false;
	OnStart();
}

void ChildScene::Update(float deltaTime) {
	OnUpdate(deltaTime);
}

void ChildScene::End() {
	OnEnd();
}

bool ChildScene::IsEnd() const {
	return m_IsEnd;
}

SceneName ChildScene::Next() const {
	return m_Next;
}

void ChildScene::Change(const SceneName next) {
	m_IsEnd = true;
	m_Next = next;
}

void ChildScene::SetParent(const IScenePtr & parent) {
	p_Parent = parent;
}

void ChildScene::HandleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::END_SCENE:
		Change((const SceneName&)param);
		break;
	}
}

void ChildScene::ReleaseWorld() {
	p_World = nullptr;
}
