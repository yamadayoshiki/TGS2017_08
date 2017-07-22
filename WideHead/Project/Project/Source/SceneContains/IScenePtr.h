#ifndef ISCENE_PTR_H_
#define ISCENE_PTR_H_

#include <memory>

//シーンポインタ
class IScene;
using IScenePtr = std::shared_ptr<IScene>;
using ISceneWPtr = std::weak_ptr<IScene>;

#endif // !ISCENE_PTR_H_
