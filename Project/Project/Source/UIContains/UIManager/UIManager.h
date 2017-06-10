#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

#include "../UIType.h"
#include "../UIFilePaths.h"

#include <unordered_map>

enum class SceneName;

// UI�}�l�[�W���[
class UIManager : public Actor {
public:
	// �R���X�g���N�^
	UIManager(IWorld* world, const IGameManagerPtr& gameManakkoger, const SceneName& scene);

private:
	// �e�V�[���̃p�X�̓o�^
	void regist();
	// �V�[���ɑΉ�����UI�̐���
	void create(const SceneName& scene_name);

private:
	// UI�o�^�p��map
	std::unordered_map<SceneName, UIFilePaths>m_FilePaths;
};