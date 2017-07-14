#ifndef BODYFACTORYPTR_H_
#define BODYFACTORYPTR_H_
#include <memory>
namespace Body {
	class BodyFactory;
	using BodyFactoryUPtr = std::unique_ptr<BodyFactory>;
}

#endif // !BODYFACTORYPTR_H_
