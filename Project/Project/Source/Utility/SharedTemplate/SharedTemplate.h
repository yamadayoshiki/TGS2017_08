#pragma once

#include <memory>

template<class T>
class SharedTemplate : public std::enable_shared_from_this<T> {
public:
	SharedTemplate(){}
};