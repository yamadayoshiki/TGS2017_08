#ifndef SCENECHILDMGR_H_
#define SCENECHILDMGR_H_
#include "SceneManager.h"
//�V�[���̓���q
class SceneChildMgr : public SceneManager
{
public:
	explicit SceneChildMgr(const IScenePtr& parent);
	~SceneChildMgr();

public:
	// �V�[���̒ǉ�    
	void Add(SceneName name, const IScenePtr& child) override;

public:
	//�q�̐ݒ�
	void SetUpChild();
	//�q��world���
	void ReleaseWorld();

private:
	// �R�s�[�֎~     
	SceneChildMgr(const SceneChildMgr& other) = delete;
	SceneChildMgr& operator = (const SceneChildMgr& other) = delete;

private:
	ISceneWPtr p_Parent;	//�e
};
#endif // !SCENECHILDMGR_H_