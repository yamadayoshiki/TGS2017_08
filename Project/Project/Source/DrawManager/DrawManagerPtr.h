#ifndef DRAWMANAGERPTR_H_
#define DRAWMANAGERPTR_H_
#include <memory>
class DrawManager;
using DrawManagerSPtr = std::shared_ptr<DrawManager>;
using DrawManagerWPtr = std::weak_ptr<DrawManager>;
#endif
