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

	void SetParent(const IScenePtr& parent);
protected:
	ISceneWPtr p_Parent;	//親
};
#endif // !CHILDSCENE_H_
