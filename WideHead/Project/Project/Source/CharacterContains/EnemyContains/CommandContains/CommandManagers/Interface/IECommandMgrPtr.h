#ifndef IENEMYCOMMANDMANAGERPTR_H_
#define IENEMYCOMMANDMANAGERPTR_H_
#include <memory>
class IECommandMgr;
using IECommandMgrUPtr = std::unique_ptr<IECommandMgr>;
#endif
