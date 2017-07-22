#ifndef TRANSFORMPTR_H_
#define TRANSFORMPTR_H_
#include <memory>
class Transform;
using TransformPtr = std::shared_ptr<Transform>;
#endif // !TRANSFORMPTR_H_