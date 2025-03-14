#pragma once

#include <iostream>
#include <vector>

namespace recipe_2_01
{
    inline void
    execute()
    {
        {
            [[maybe_unused]] int age        = 42;
            [[maybe_unused]] int attendance = 96321;
        }

        {
            [[maybe_unused]] unsigned int       length   = 32;
            [[maybe_unused]] short              year     = 2023; // same as short int
            [[maybe_unused]] unsigned long long filesize = 3'758'096'384;
        }

        {
            std::vector<int>             arr{1, 2, 3};
            [[maybe_unused]] std::size_t items = arr.size();
        }

        {
            [[maybe_unused]] double      price       = 4.99;
            [[maybe_unused]] float       temperature = 36.5;
            [[maybe_unused]] long double pi          = 3.14159265358979323846264338327950288419716939937510L;
        }

        {
            std::int8_t x = 42;
            std::cout << x << '\n'; // [1] prints *

            std::int16_t y = 42;
            std::cout << y << '\n'; // [2] prints 42
        }

        {
            [[maybe_unused]] auto a = 4'234'871'523ll;
            [[maybe_unused]] auto b = 0xBAAD'F00D;
            [[maybe_unused]] auto c = 00'12'34;
            [[maybe_unused]] auto d = 0b1011'0101'0001'1001;

            [[maybe_unused]] auto e = 1'2'3'4'5;
        }
    }
} // namespace recipe_2_01
