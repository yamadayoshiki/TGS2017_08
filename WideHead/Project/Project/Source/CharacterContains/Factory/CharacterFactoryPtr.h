#ifndef CHARACTERFACTORYPTR_H_
#define CHARACTERFACTORYPTR_H_

#include <memory>
class CharacterFactory;
using CharacterFactoryUPtr = std::unique_ptr<CharacterFactory>;

#endif // !CHARACTERFACTORYPTR_H_
