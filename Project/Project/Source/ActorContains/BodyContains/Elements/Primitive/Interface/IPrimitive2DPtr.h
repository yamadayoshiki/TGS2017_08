#ifndef IPRIMITIVE2DPTR_H_
#define IPRIMITIVE2DPTR_H_
#include <memory>
namespace Body {
	struct IPrimitive2D;
	using IPrimitive2DSPtr = std::shared_ptr<IPrimitive2D>;
}
#endif // !IPRIMITIVE2DPTR_H_
