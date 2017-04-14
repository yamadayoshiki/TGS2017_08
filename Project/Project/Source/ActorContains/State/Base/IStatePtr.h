#pragma once

#include <memory>

// ステートポインタ
class IState;
using IStatePtr = std::shared_ptr<IState>;
