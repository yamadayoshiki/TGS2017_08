#include "SceneChildMgr.h"
#include "../Scene/Scene.h"
#include "../Scene/ChildScene.h"
SceneChildMgr::SceneChildMgr(const IScenePtr& parent)
	: p_Parent(parent) {
}

SceneChildMgr::~SceneChildMgr() {
}

void SceneChildMgr::Add(SceneName name, const IScenePtr & child) {
	SceneManager::Add(name, child);

	p_Parent.lock()->SetUpChild(*dynamic_cast<ChildScene*>(m_SceneDic[name].get()));
}

void SceneChildMgr::SetUpChild() {
	for (auto itr = m_SceneDic.begin(); itr != m_SceneDic.end(); itr++)
		p_Parent.lock()->SetUpChild((*dynamic_cast<ChildScene*>(itr->second.get())));
}

