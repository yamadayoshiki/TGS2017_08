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

	void SetParent(const IScenePtr& parent);
protected:
	ISceneWPtr p_Parent;	//�e
};
#endif // !CHILDSCENE_H_
