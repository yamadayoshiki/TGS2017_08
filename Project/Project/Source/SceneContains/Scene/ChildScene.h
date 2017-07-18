#ifndef CHILDSCENE_H_
#define CHILDSCENE_H_
#include "Scene.h"
#include "../IScenePtr.h"
//子シーン
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

protected:
	//変更
	void Change(const SceneName next);

	void SetParent(const IScenePtr& parent);
protected:
	ISceneWPtr p_Parent;	//親
	SceneName m_Next;		//次のシーン
};
#endif // !CHILDSCENE_H_
