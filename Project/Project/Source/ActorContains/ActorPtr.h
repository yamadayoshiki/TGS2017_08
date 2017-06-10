#ifndef ACTORPTR_H_
#define ACTORPTR_H_

#include <memory>

class Actor;
using ActorPtr = std::shared_ptr<Actor>;
using ActorWPtr = std::weak_ptr<Actor>;
using ActorUPtr = std::unique_ptr<Actor>;

#endif // ! ACTORPTR_H_