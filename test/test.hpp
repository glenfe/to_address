#ifndef TEST_HPP
#define TEST_HPP

#include <cstdio>

inline int& result()
{
    static int r;
    return r;
}

inline bool test(const char* e, const char* f, int l, bool v)
{
    if (!v) {
        std::fprintf(stderr, "%s:%d: failed '%s'\n", f, l, e);
        result() = 1;
    }
    return v;
}

#define TEST(e) (test(#e, __FILE__, __LINE__, (e) ? true : false))

#endif
