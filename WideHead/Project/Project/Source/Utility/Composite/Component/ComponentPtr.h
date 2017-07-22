#ifndef COMPONENTPTR_H_
#define COMPONENTPTR_H_
#include <memory>
class Component;
using ComponentSPtr = std::shared_ptr<Component>;
using ComponentWPtr = std::weak_ptr<Component>;
#endif // !COMPONENTPTR_H_
