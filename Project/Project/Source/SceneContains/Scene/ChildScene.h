#ifndef CHILDSCENE_H_
#define CHILDSCENE_H_
#include "Scene.h"
#include "../IScenePtr.h"

//�q�V�[��
class ChildScene : public Scene
{
public:
	ChildScene();
	~ChildScene();

public:
	void Start()override;

	void Update(float deltaTime)override;

	void Draw()const override {}

	void End() override;

	bool IsEnd() const override;

	SceneName Next() const override;

	void SetParent(const IScenePtr& parent);

	void HandleMessage(EventMessage message, void * param) override;

	void ReleaseWorld();

protected:
	//�ύX
	void Change(const SceneName next);

protected:
	ISceneWPtr p_Parent;	//�e
	SceneName m_Next;		//���̃V�[��
};
#endif // !CHILDSCENE_H_
