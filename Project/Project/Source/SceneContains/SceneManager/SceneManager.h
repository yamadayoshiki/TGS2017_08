#ifndef SCENEMANAGER_H_ 
#define SCENEMANAGER_H_ 

#include "../IScenePtr.h"
#include <unordered_map> 

enum class SceneName;
enum class EventMessage;
// �V�[���Ǘ��N���X
class SceneManager
{
public:
	// �R���X�g���N�^     
	SceneManager();
	// �Z�b�g�A�b�v
	void SetUp();
	// ������     
	void Initialize();
	// �X�V     
	void Update(float deltaTime);
	// �`��     
	void Draw() const;
	// �I��     
	void End();
	// �V�[���̒ǉ�    
	virtual void Add(SceneName name, const IScenePtr& scene);
	// �V�[���̕ύX     
	void Change(SceneName name);
	// �V�[�����̎擾     
	SceneName GetSceneName();
	// ���b�Z�[�W����
	void HandleMessage(EventMessage message, void* param);
	// �R�s�[�֎~     
	SceneManager(const SceneManager& other) = delete;
	SceneManager& operator = (const SceneManager& other) = delete;

protected:
	// �V�[��     
	std::unordered_map<SceneName, IScenePtr> m_SceneDic;
	// ���݂̃V�[��     
	IScenePtr m_CurrentScene;
};

#endif