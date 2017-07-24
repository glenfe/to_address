/*
Copyright 2017 Glen Joseph Fernandes (glenjofe@gmail.com)
Distributed under the Boost Software License, Version 1.0.
*/
#ifndef GTL_TO_ADDRESS_HPP
#define GTL_TO_ADDRESS_HPP

#include <memory>

namespace gtl {

template<class T>
constexpr T* to_address(T* p) noexcept
{
    return p;
}

template<class T>
inline auto to_address(const T& p) noexcept
-> decltype(std::pointer_traits<T>::to_address(p))
{
    return std::pointer_traits<T>::to_address(p);
}

template<class T, class... U>
inline auto to_address(const T& p, U...) noexcept
{
    return gtl::to_address(p.operator->());
}

} /* gtl */

#endif
