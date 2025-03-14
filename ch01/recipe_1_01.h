#pragma once

#include <cctype>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

// #include <vector>
// #include <memory>

namespace recipe_1_01
{
    using namespace std::string_literals;

    class foo
    {
        int x;

      public:
        foo(int const value = 0) : x{value}
        {
        }

        int &
        get()
        {
            return x;
        }
    };

    inline auto
    proxy_get(foo &f)
    {
        return f.get();
    }

    inline decltype(auto)
    proxy_get2(foo &f)
    {
        return f.get();
    }

    struct L
    {
        template <typename T, typename U>
        auto
        operator()(T const a, U const b) const
        {
            return a + b;
        }
    };

    inline void
    execute()
    {
        {
            auto i [[maybe_unused]] = 42;                                           // int
            auto d [[maybe_unused]] = 42.5;                                         // double
            auto s [[maybe_unused]] = "text";                                       // const char*
            auto b [[maybe_unused]] = new char[10]{0};                              // char*
            auto p [[maybe_unused]] = std::make_shared<int>(42);                    // std::shared_ptr<int>
            auto v [[maybe_unused]] = {1, 2, 3};                                    // std::initializer_list<int>
            auto l [[maybe_unused]] = [](char const c) { return std::toupper(c); }; // int(char)
        }

        {
            auto s = std::string{"text"};                                           // std::string
            auto v = std::vector<int>{1, 2, 3};                                     // std::vector<int>
        }

        {
            auto v                      = std::vector<int>{1, 2, 3};
            int  size1 [[maybe_unused]] = v.size(); // implicit conversion, possible loss of data
            auto size2 [[maybe_unused]] = v.size();
            // auto size3 [[maybe_unused]] = int{v.size()}; // error, narrowing conversion
        }

        {
            std::map<int, std::string> m;

            for (std::map<int, std::string>::const_iterator it = m.cbegin(); it != m.cend(); ++it)
            {
            }

            for (auto it = m.cbegin(); it != m.cend(); ++it)
            {
            }
        }

        {
            foo  f(42);
            auto x [[maybe_unused]] = f.get();
            x                       = 100;
            std::cout << f.get() << '\n'; // prints 42
        }

        {
            // auto l1 = long long{42};      // error

            using llong              = long long;
            auto l2 [[maybe_unused]] = llong{42}; // OK
            auto l3 [[maybe_unused]] = 42LL;      // OK
        }

        {
            auto f = foo{42};
            // auto &x = proxy_get(f); // cannot convert from 'int' to 'int &'
        }

        {
            auto           f                  = foo{42};
            decltype(auto) x [[maybe_unused]] = proxy_get2(f);
        }

        {
            auto ladd = [](auto const a, auto const b) { return a + b; };

            auto i [[maybe_unused]] = ladd(40, 2);            // 42
            auto s                  = ladd("forty"s, "two"s); // "fortytwo"s
        }
    }

    inline auto
    func1(int const i) -> int
    {
        return 2 * i;
    }

    inline auto
    func2(int const i)
    {
        return 2 * i;
    }
} // namespace recipe_1_01
