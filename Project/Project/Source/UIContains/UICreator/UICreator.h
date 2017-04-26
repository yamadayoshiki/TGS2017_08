#pragma once

#include "../../ActorContains/ActorPtr.h"
#include "../../SceneContains/SceneName.h"
#include "../../WorldContains/IWorldPtr.h"
#include "../../Base/GameManagerContains/IGameManagerPtr.h"

#include <unordered_map>

// UI�����N���X
class UICreator {
public:
	// �R���X�g���N�^
	UICreator(const IWorldPtr& world, const IGameManagerPtr& gameManager);
	// �f�X�g���N�^
	~UICreator();
	// UI�̓o�^
	void regist();
	// �V�[���ɑΉ�����UI�̐���
	void create(const SceneName& scene_name);
private:
	// ���[���h
	IWorldPtr p_World;
	// �Q�[���}�l�[�W���[
	IGameManagerPtr p_GameManager;
	// UI�o�^�p��map
	std::unordered_map<SceneName, ActorPtr>m_UIManagers;
};