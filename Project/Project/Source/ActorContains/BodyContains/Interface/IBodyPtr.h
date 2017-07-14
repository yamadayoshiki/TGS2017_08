#ifndef IBODYPTR_H_
#define IBODYPTR_H_
#include <memory>
namespace Body {
	class IBody;
	using IBodyPtr = std::shared_ptr<IBody>;
	using IBodyUPtr = std::unique_ptr<IBody>;
}
#endif // !ICODYPTR_H_

