#pragma once

#include <iostream>
#include <string>

namespace recipe_2_03
{
    inline void
    execute()
    {
        auto si  = std::to_string(42);    // si="42"
        auto sl  = std::to_string(42l);   // sl="42"
        auto su  = std::to_string(42u);   // su="42"
        auto sd  = std::to_string(42.0);  // sd="42.000000"
        auto sld = std::to_string(42.0l); // sld="42.000000"

        [[maybe_unused]] auto i1 = std::stoi("42");
        [[maybe_unused]] auto i2 = std::stoi("   42");
        [[maybe_unused]] auto i3 = std::stoi("   42fortytwo");
        [[maybe_unused]] auto i4 = std::stoi("+42");
        [[maybe_unused]] auto i5 = std::stoi("-42");

        [[maybe_unused]] auto i6  = std::stoi("052", nullptr, 8);    // i6 = 42
        [[maybe_unused]] auto i7  = std::stoi("052", nullptr, 0);    // i7 = 42
        [[maybe_unused]] auto i8  = std::stoi("0x2A", nullptr, 16);  // i8 = 42
        [[maybe_unused]] auto i9  = std::stoi("0x2A", nullptr, 0);   // i9 = 42
        [[maybe_unused]] auto i10 = std::stoi("101010", nullptr, 2); // i10 = 42
        [[maybe_unused]] auto i11 = std::stoi("22", nullptr, 20);    // i11 = 42
        [[maybe_unused]] auto i12 = std::stoi("-22", nullptr, 20);   // i12 = -42

        [[maybe_unused]] auto pos = size_t{0};
        [[maybe_unused]] auto i13 = std::stoi("42", &pos);           // i13 = 42,  pos = 2
        [[maybe_unused]] auto i14 = std::stoi("-42", &pos);          // i14 = -42, pos = 3
        [[maybe_unused]] auto i15 = std::stoi("  +42dec", &pos);     // i15 = 42,  pos = 5

        try
        {
            [[maybe_unused]] auto i16 = std::stoi("");
        }
        catch (std::exception const &e)
        {
            // prints "invalid stoi argument"
            std::cout << e.what() << '\n';
        }

        try
        {
            [[maybe_unused]] auto i17 = std::stoll("12345678901234"); // OK
            [[maybe_unused]] auto i18 = std::stoi("12345678901234");  // throws std::out_of_range
        }
        catch (std::exception const &e)
        {
            // prints stoi argument out of range
            std::cout << e.what() << '\n';
        }

        [[maybe_unused]] auto d1 = std::stod("123.45");       // d1 =  123.45000000000000
        [[maybe_unused]] auto d2 = std::stod("+123.45");      // d2 =  123.45000000000000
        [[maybe_unused]] auto d3 = std::stod("-123.45");      // d3 = -123.45000000000000
        [[maybe_unused]] auto d4 = std::stod("  123.45");     // d4 =  123.45000000000000
        [[maybe_unused]] auto d5 = std::stod("  -123.45abc"); // d5 = -123.45000000000000
        [[maybe_unused]] auto d6 = std::stod("1.2345e+2");    // d6 =  123.45000000000000
        [[maybe_unused]] auto d7 = std::stod("0xF.6E6666p3"); // d7 =  123.44999980926514

        [[maybe_unused]] auto d8  = std::stod("INF");         // d8 = inf
        [[maybe_unused]] auto d9  = std::stod("-infinity");   // d9 = -inf
        [[maybe_unused]] auto d10 = std::stod("NAN");         // d10 = nan
        [[maybe_unused]] auto d11 = std::stod("-nanabc");     // d11 = -nan
    }
} // namespace recipe_2_03
