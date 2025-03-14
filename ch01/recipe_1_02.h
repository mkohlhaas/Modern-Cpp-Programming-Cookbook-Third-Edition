#pragma once

#include <string>
#include <vector>

namespace recipe_1_02
{
    typedef unsigned char  byte;
    typedef unsigned char *byte_ptr;
    typedef int            array_t[10];
    // typedef void(*fn)(byte, double);

    template <typename T>
    class foo
    {
        typedef T value_type;
    };

    typedef struct
    {
        int value;
    } bar, *pbar;

    // this is OK
    typedef std::vector<int> vint_t;
    vint_t                   v;

    // this is not possible
    // typedef std::vector<T> vec_t;
    // vec_t<int> v;

    template <typename T>
    using vec_t = std::vector<T>;

    template <class T>
    class custom_allocator
    { /* ... */
    };

    template <typename T>
    using vec_t_ca = std::vector<T, custom_allocator<T>>;

    inline void
    func(byte, double)
    {
    }

    typedef int INTEGER;

    INTEGER x = 10;

    typedef int INTEGER;

    INTEGER y = 20;

    inline void
    execute()
    {
        {
            using byte     = unsigned char;
            using byte_ptr = unsigned char *;
            using array_t  = int[10];
            using fn       = void(byte, double);

            [[maybe_unused]] byte     b{42};
            [[maybe_unused]] byte_ptr pb = new byte[10]{0};
            [[maybe_unused]] array_t  a{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            fn                       *f = func;
            f(1, 42.0);
        }

        {
            vec_t<int>         vi;
            vec_t<std::string> vs;
        }
    }
} // namespace recipe_1_02
