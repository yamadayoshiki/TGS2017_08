#ifndef ANIMATIONPTR_H_
#define ANIMATIONPTR_H_
#include <memory>
class Animation;
using AnimationSPtr = std::shared_ptr<Animation>;
using AnimationWPtr = std::weak_ptr<Animation>;
#endif // !AnimationPtr_H_
