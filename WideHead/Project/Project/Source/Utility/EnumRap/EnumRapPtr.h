#pragma once

#include<memory>

template <typename T> class EnumRap;
template <typename T> using EnumRapPtr = std::shared_ptr<EnumRap<T>>;
