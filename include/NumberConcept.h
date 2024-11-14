#pragma once

#include <concepts>

template <typename T>
concept Number = (std::is_default_constructible<T>::value || std::integral<T> || std::floating_point<T>);