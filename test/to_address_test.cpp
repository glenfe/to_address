/*
Copyright 2017 Glen Joseph Fernandes (glenjofe@gmail.com)
Distributed under the Boost Software License, Version 1.0.
*/
#include <gtl/to_address.hpp>
#include <cstdio>

int result = 0;

inline void test(const char* e, int l, bool v)
{
    if (!v) {
        std::fprintf(stderr, "%d: '%s' failed\n", l, e);
        result = 1;
    }
}

#define TEST(e) test(#e, __LINE__, (e))

template<class T>
class P1 {
public:
    explicit P1(T* p)
        : p_(p) { }

    T* operator->() const noexcept {
        return p_;
    }

private:
    T* p_;
};

template<class T>
class P2 {
public:
    explicit P2(T* p)
        : p_(p) { }

    P1<T> operator->() const noexcept {
        return p_;
    }

private:
    P1<T> p_;
};

template<class T>
class P3 {
public:
    explicit P3(T* p)
        : p_(p) { }

    T* get() const noexcept {
        return p_;
    }

private:
    T* p_;
};

namespace std {

template<class T>
struct pointer_traits<P3<T> > {
    static T* to_address(const P3<T>& p) noexcept {
        return p.get();
    }
};

} /* std */

template<class T>
class P4 {
public:
    explicit P4(T* p)
        : p_(p) { }

    T* operator->() const noexcept {
        return nullptr;
    }

    T* get() const noexcept {
        return p_;
    }

private:
    int* p_;
};

namespace std {

template<class T>
struct pointer_traits<P4<T> > {
    static T* to_address(const P4<T>& p) noexcept {
        return p.get();
    }
};

} /* std */

int main()
{
    int i = 0;
    TEST(gtl::to_address(&i) == &i);
    int* p = &i;
    TEST(gtl::to_address(p) == &i);
    P1<int> p1(&i);
    TEST(gtl::to_address(p1) == &i);
    P2<int> p2(&i);
    TEST(gtl::to_address(p2) == &i);
    P3<int> p3(&i);
    TEST(gtl::to_address(p3) == &i);
    P4<int> p4(&i);
    TEST(gtl::to_address(p4) == &i);
    return result;
}
